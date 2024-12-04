## Understanding the exercise better

## Magic System
### 1. Spells (Materia)
* **Spell Types:**
  * Ice
  * Cure
  * ... (other types can be added)
* **Hierarchy:**
  * Base class: AMateria
  * Derived classes: Ice, Cure

### 2. Spell Source (MateriaSource)
* **Functionality:**
  * Learn new spells
  * Create copies of spells
* **Role:** Spell factory

### 3. Characters
* **Inventory:**
  * Capacity for up to 4 spells
* **Actions:**
  * Equip spells
  * Unequip spells
  * Cast spells on other characters

### 4. System Objectives
* **Creation:**
  * Instantiate spell class objects
* **Equipment:**
  * Associate spells with characters
* **Usage:**
  * Use spells in combat or other interactions
* **Demonstration of Concepts:**
  * Inheritance: Relationship between AMateria and its subclasses
  * Polymorphism: Treating different spell types as a base type
  * Interfaces: (If interfaces are defined, describe them here)
  * Memory Management: Ensure correct allocation and deallocation of memory


## Component map

| Class/Interface | Attributes | Methods |
|---|---|---|
| **AMateria** (Abstract) | `+ type: std::string` | `+ getType() const` <br> `+ clone() = 0 (abstract)` <br> `+ use(ICharacter&)` |
| **Ice** (Concrete) |  | `+ clone()` <br> `+ use(target)` <br> `"ice"` |
| **Cure** (Concrete) |  | `+ clone()` <br> `+ use(target)` <br> `"cure"` |
| **ICharacter** (Interface) |  | `+ getName() const` <br> `+ equip(AMateria* m)` <br> `+ unequip(int idx)` <br> `+ use(int idx, ICharacter&)` |
| **Character** | `- name` <br> `- inventory[4]` | `+ equip` <br> `+ unequip` <br> `+ use` |
| **IMateriaSource** (Interface) |  | `+ learnMateria(AMateria*)` <br> `+ createMateria(string)` |
| **MateriaSource** | `- templates[4]` | `+ learnMateria` <br> `+ createMateria` |

## Action Table

| Component | Function | Description |
|---|---|---|
| AMateria | clone | Creates a copy of the spell. Abstract method, implemented by derived classes. |
| AMateria | use | Executes an action associated with the spell. Example: "Ice casts an ice bolt". |
| Ice | clone | Returns a new instance of Ice. |
| Ice | use | Displays "* shoots an ice bolt at <name> *". |
| Cure | clone | Returns a new instance of Cure. |
| Cure | use | Displays "* heals <name>'s wounds *". |
| ICharacter | equip | Adds a spell to the inventory (maximum of 4). |
| ICharacter | unequip | Removes a spell from the inventory without deleting it. |
| ICharacter | use | Uses the spell at the specified index. |
| Character | equip | Finds the first empty slot and equips the spell. |
| Character | unequip | Removes the spell and stores the pointer for later use. |
| Character | use | Passes control to AMateria::use |
| IMateriaSource | learnMateria | Saves a spell as a template for future cloning. |
| IMateriaSource | createMateria | Creates a new instance based on the requested type. |
| MateriaSource | learnMateria | Clones and stores spells. |
| MateriaSource | createMateria | Returns a copy of the spell of the specified type, if available. |
