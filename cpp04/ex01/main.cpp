#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Default Test ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "=== Creating Animal Array ===" << std::endl;
	int animalAmount = 8;
	const Animal* animals[animalAmount];

	for (int i = 0; i < animalAmount / 2; i++)
		animals[i] =  new Dog;

	for (int i = animalAmount / 2; i < animalAmount; i++)
		animals[i] = new Cat();

	for (int i = 0; i < animalAmount; i++)
		animals[i]->makeSound();

	for (int i = 0; i < animalAmount; i++)
		delete animals[i];

	std::cout << "=== Brain Test ===" << std::endl;
	Cat cat1;
	cat1.getBrain()->setIdea(0, "eating fish");
	cat1.getBrain()->setIdea(1, "sleeping");
	Cat cat2(cat1);
	std::cout << "Cat2's first idea: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2's second idea: " << cat2.getBrain()->getIdea(1) << std::endl;
	Cat cat3;
	cat3 = cat1;
	std::cout << "Cat3's first idea: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat3's second idea: " << cat2.getBrain()->getIdea(1) << std::endl;

	const Animal* test = new Animal(); // allowed
	test->makeSound();
	delete test;
	return 0;
}