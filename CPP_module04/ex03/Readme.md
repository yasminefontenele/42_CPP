## Understanding the exercise better

## Sistema de Magias

### 1. Magias (Materias)
* **Tipos de Magias:**
  * Ice (gelo)
  * Cure (cura)
  * ... (outros tipos podem ser adicionados)
* **Hierarquia:**
  * Classe base: AMateria
  * Classes derivadas: Ice, Cure

### 2. Fonte de Magias (MateriaSource)
* **Funcionalidade:**
  * Aprender novas magias
  * Criar cópias de magias
* **Papel:** Fábrica de magias

### 3. Personagens (Characters)
* **Inventário:**
  * Capacidade para até 4 magias
* **Ações:**
  * Equipar magias
  * Desequipar magias
  * Usar magias em outros personagens

### 4. Objetivo do Sistema
* **Criação:**
  * Instanciar objetos das classes de magia
* **Equipamento:**
  * Associar magias a personagens
* **Uso:**
  * Utilizar magias em combate ou outras interações
* **Demonstração de Conceitos:**
  * Herança: Relação entre AMateria e suas subclasses
  * Polimorfismo: Tratamento de diferentes tipos de magias como um tipo base
  * Interfaces: (Se houver interfaces definidas, descrevê-las aqui)
  * Manipulação de Memória: Garantir a alocação e liberação corretas de memória


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
