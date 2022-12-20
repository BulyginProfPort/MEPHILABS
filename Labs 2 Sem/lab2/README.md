# АТД (Абстрактный тип данных)

## Техническое задание

Написать на языке C++ реализацию **полиморфного абстрактного типа данных** – с помощью нескольких уровней абстракции. 
На нижем уровне реализуются структуры для организации данных в памяти – динамический массив и связанный список. 
Уровнем выше располагается абстракция **(АТД последовательность)**, обеспечивающая возможности унифицированной работы со всеми структурами нижнего уровня. 

Целевой АТД, реализация которого и является конечной целью задания, располагается на самом верхнем уровне и использует АТД последовательность для реализации большинства операций.

**Целевой абстрактный тип данных** - квадратная матрица, но так же есть задел для реализации прямоугольной или иной матрицы размера m x n

## Схема реализации технического задания
<img width="750" alt="Снимок экрана 2022-05-22 в 21 13 22" src="https://user-images.githubusercontent.com/89743034/169709659-5b88550b-ce20-4a24-8043-24adfa7d73ec.png">

## Реализация классов
Классы реализовывались на шаблонах
### class Dynamic Array
- DynamicArray(int k)
- DynamicArray(T* const arrIn, int k)
- DynamicArray(DynamicArray<T> const &arrIn )
- T Get(int index) const{
- int GetSize() const{
- void Set(T value, int index){
- void ReSize(int nSize){


### class Linked List
- LinkedList(T* arr,int k)
- LinkedList()
- LinkedList<T>(LinkedList<T> const &listIn)
- T GetFirstValue() const
- T GetLastValue() const
- T Get(int index) const
- LinkedList <T> GetSubList(int startIndex,int endIndex)
- int GetLength() const
- void Append(T value)
- void Prepend(T value)
- void InsertAt(T item,int index)
- LinkedList <T> Concat(LinkedList<T> *listIn){

### class Array Sequence
- ArraySequence()
- ArraySequence(T* const arr, int k)


### class List Sequence

### class Sequence
  
