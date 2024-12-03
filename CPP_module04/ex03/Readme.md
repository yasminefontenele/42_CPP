AMateria (Classe Abstrata)         ICharacter (Interface)
+--------------------------+       +---------------------------+
| + type: std::string      |       | + getName() const         |
| + getType() const        |       | + equip(AMateria* m)      |
| + clone() = 0 (abstract) |       | + unequip(int idx)        |
| + use(ICharacter&)       |       | + use(int idx, ICharacter&)|
+--------------------------+       +---------------------------+
          ↑                                    ↑
+------------------+                 +------------------+
| Ice (Concreto)   |                 | Character        |
| + clone()        |                 | - name           |
| + use(target)    |                 | - inventory[4]   |
| "ice"            |                 | + equip          |
+------------------+                 | + unequip        |
          ↑                          | + use            |
+------------------+                 +------------------+
| Cure (Concreto)  |
| + clone()        |
| + use(target)    |
| "cure"           |
+------------------+

IMateriaSource (Interface)
+--------------------------+
| + learnMateria(AMateria*)|
| + createMateria(string)  |
+--------------------------+
          ↑
+--------------------------+
| MateriaSource            |
| - templates[4]           |
| + learnMateria           |
| + createMateria          |
+--------------------------+


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
