#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to show success message
success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

# Function to show failure message
fail() {
    echo -e "${RED}[FAILURE]${NC} $1"
    exit 1
}

# Function to test specific input
test_input() {
    local description=$1
    local input=$2
    local expected_output=$3
    local should_fail=$4

    echo -e "${YELLOW}Testing:${NC} $description"
    
    if [ "$should_fail" = true ]; then
        # Test that should fail
        ./PmergeMe $input 2>/dev/null && fail "Test should have failed: $description" || success "Failed as expected: $description"
    else
        # Test that should pass
        result=$(./PmergeMe $input 2>&1 | grep "After:" | cut -d':' -f2- | xargs)
        if [ "$result" = "$expected_output" ]; then
            success "Correct output for: $description"
        else
            fail "Incorrect output. Expected: '$expected_output', Got: '$result'"
        fi
    fi
    echo ""
}

# Compile the program (if not already compiled)
echo "Compiling the program..."
make re || fail "Failed to compile the program"

# Basic functionality tests
echo "=== BASIC TESTS ==="
test_input "Simple sorting" "3 1 4 2 5" "1 2 3 4 5" false
test_input "Repeated numbers" "5 5 2 2 1" "1 2 2 5 5" false
test_input "Single number" "42" "42" false
test_input "Descending order numbers" "5 4 3 2 1" "1 2 3 4 5" false

# Error handling tests
echo "=== ERROR TESTS ==="
test_input "Negative number" "-1 2 3" "" true
test_input "Zero" "0 1 2" "" true
test_input "Non-numeric character" "1 a 3" "" true
test_input "Very large number" "999999999999999999 1" "" true

# Performance tests with large number sets
echo "=== PERFORMANCE TESTS ==="

# Generate 3000 unique random numbers between 1-10000
echo "Generating 3000 random numbers..."
RANDOM_NUMS=$(shuf -i 1-10000 -n 3000 | tr "\n" " ")
SORTED_NUMS=$(echo $RANDOM_NUMS | tr " " "\n" | sort -n | tr "\n" " " | xargs)

echo "Testing with 3000 numbers..."
start_time=$(date +%s.%N)
./PmergeMe $RANDOM_NUMS > /tmp/pmergeme_output
end_time=$(date +%s.%N)

# Verify correct sorting
result=$(grep "After:" /tmp/pmergeme_output | cut -d':' -f2- | xargs)
if [ "$result" = "$SORTED_NUMS" ]; then
    elapsed=$(echo "$end_time - $start_time" | bc)
    success "Correctly sorted 3000 numbers in $elapsed seconds"
else
    fail "Failed to correctly sort 3000 numbers"
fi

# Stress test with upper limit
echo "Testing with upper input limit..."
HUGE_INPUT=$(seq 1 5000 | shuf | head -n 3000 | tr "\n" " ")
./PmergeMe $HUGE_INPUT > /dev/null && success "Handled large input successfully" || fail "Failed with large input"

# Valgrind memory leak test
echo ""
echo "=== VALGRIND TEST ==="
if command -v valgrind &> /dev/null; then
    valgrind --leak-check=full --error-exitcode=1 ./PmergeMe 3 1 4 2 5 2>/dev/null
    if [ $? -eq 0 ]; then
        success "Valgrind: No memory leaks detected"
    else
        fail "Valgrind: Memory leaks detected"
    fi
else
    echo "Valgrind not installed. Skipping memory test."
fi

echo -e "\n${GREEN}All tests completed successfully!${NC}"