# Task 1

## Напишете клас BasicInfo, който има следните характеристики:
- ЕГН - низ
- Име - низ
- Фамилия - низ
- Адрес - низ
### Създайте:
  - конструктор с 5 параметъра (характеристиките)
  - гетъри за ЕГН-то и името
  - предефинирайте операторите за вход и изход за работа с двоичен файл


## Напишете клас User, който има следните характеристики:
- BasicInfo
- Потребителско име
- Парола
- PhoneNumber
### Създайте:
  - констуктор с подходящи параметри
  - гетъри за потребителско име и телефонен номер
  - предефинирайте операторите за вход и изход за работа с двоичен файл

## PhoneNumber да има следните характеристики:
- телефонен номер (низ)
### Създайте:
  - конструктор
  - гетър за низа
  - функции:
    - serialize(std::ostream& os), която записва телефона в двоичен файл
    - deserialize(std::istream& is), която чете телефона от двоичен файл

# Task 2
Напишете следните класове:

**Account**, който има:
- char* owner
- size_t id
- double balance

Класът не може да има дефолтен конструктор.

**Bank**, който има:
- масив от акаунтите
- други променливи нужни за поддържането на масива
- size_t currentId; *(при създаване на банката се дава начална стойност на currentId и после се увеличава с 1 при всяко добавяне на нов акаунт)*

 Вие преценете как трябва да бъде реализиран и какво друго му е необходимо - трябва да може да се разширява капацитета!

 Програмата трябва да позволява следните операции:
 - Отваряне на акаунт по дадено име, id-то се генерира от банката
 - Транзакция: Теглене на пари от акаунт по дадено id и сума *(за целта трябва да има достатчъно пари в сметката)*
 - Транзакция: Добавяне на пари в акаунт по дадено id и сума
 - Транзакция: Изпращане на пари от един акаунт на друг по дадени id-та и сума *(за целта и двата акаунта трябва да съществуват и изпращащия да има достатъчно пари в сметката)*

- Да се изведат на конзолата всички транзакции, в които е участвал акаунт с дадено id
- Да се изведат всички акаунти по азбучен ред

- При изпълнение на която и да е транзакция за дадено id, трябва в текстов файл с име `"transactions-<съответното id>.txt"` да се записва информaцията за нея - какъв тип е (`withdraw`, `deposit`, `send`, `receive`), сумата и ако има друг участник в транзакцията - неговото име. Ако вече съществува такъв файл, не трябва да триете вече наличните данни в него. Ако не съществува, трябва преди транзакциите да запишете информацията за акаунта.

- При стартиране на програмата да десериализирате акаунтите от файл `"bank.dat"`, ако такъв съществува.

- При приключване на програмата да сериализирате акаунтите във файл `"bank.dat"`