| Class/Interface | Attributes | Methods |
|---|---|---|
| **AMateria** (Abstract) | `+ type: std::string` | `+ getType() const` <br> `+ clone() = 0 (abstract)` <br> `+ use(ICharacter&)` |
| **Ice** (Concrete) |  | `+ clone()` <br> `+ use(target)` <br> `"ice"` |
| **Cure** (Concrete) |  | `+ clone()` <br> `+ use(target)` <br> `"cure"` |
| **ICharacter** (Interface) |  | `+ getName() const` <br> `+ equip(AMateria* m)` <br> `+ unequip(int idx)` <br> `+ use(int idx, ICharacter&)` |
| **Character** | `- name` <br> `- inventory[4]` | `+ equip` <br> `+ unequip` <br> `+ use` |
| **IMateriaSource** (Interface) |  | `+ learnMateria(AMateria*)` <br> `+ createMateria(string)` |
| **MateriaSource** | `- templates[4]` | `+ learnMateria` <br> `+ createMateria` |


## Tabela de ações
| Componente | Função | Descrição |
|---|---|---|
| AMateria | clone | Cria uma cópia da magia. Método abstrato, implementado por classes derivadas. |
| AMateria | use | Executa uma ação associada à magia. Exemplo: "Ice lança um raio de gelo". |
| Ice | clone | Retorna uma nova instância de Ice. |
| Ice | use | Mostra "* shoots an ice bolt at <name> *". |
| Cure | clone | Retorna uma nova instância de cure. |
| Cure | use | Mostra "* heals <name>'s wounds *". |
| ICharacter | equip | Adiciona uma magia ao inventário (máximo de 4). |
| ICharacter | unequip | Remove uma magia do inventário sem deletá-la. |
| ICharacter | use | Usa a magia no índice especificado. |
| Character | equip | Procura o primeiro slot vazio e equipa a magia. |
| Character | unequip | Remove a magia e armazena o ponteiro para uso posterior. |
| Character | use | Passa o controle para AMateria:: use |
| IMateriaSource | learnMateria | Salva uma magia como modelo para clonagem futura. |
| IMateriaSource | createMateria | Cria uma nova instância baseada no tipo solicitado. |
| MateriaSource | learnMateria | Clona e armazena magias. |
| MateriaSource | createMateria | Retorna uma cópia da magia do tipo especificado, se disponível. |
