#pragma once
#include <iostream>
#include <cstring>

class Question {
private:
	char question[101];
public:
	const char* getQuestion() const {
		return question;
	}
	Question(const char* q) {
		strcpy_s(question, 101, q);
	}
	virtual void askQuestion() = 0;
	virtual bool checkQuestion() const = 0;
};

class IntegerQuestion : public Question {
private:
	int answer, givenAnswer;
public:
	IntegerQuestion(int _answer, const char* q) : Question(q) {
		answer = _answer;
		givenAnswer = 0;
	}
	void askQuestion() override {
		std::cout << getQuestion() << '\n';
		std::cin >> givenAnswer;
	}
	bool checkQuestion() const override{
		return answer == givenAnswer;
	}
};

class OpenQuestion : public Question {
private:
	char givenAnswer[256];
public:
	OpenQuestion(const char* q) : Question(q) {}
	void askQuestion() override {
		std::cout << getQuestion() << '\n';
		std::cin.getline(givenAnswer, 256);
	}
	bool checkQuestion() const override {
		std::cout << givenAnswer << '\n';
		char c;
		std::cout << "Enter t if it's true\n";
		std::cin >> c;
		if (c == 't')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Test {
private:
	Question** exam;
	int size;
public:
	Test(Question ** question, int n) {
		size = n;
		question = new Question * [n];
		for (int i = 0; i < size;i++)
		{
			exam[i] = question[i];
		}
	}
	//big 4
	void performTest() {
		for (int i = 0; i < size;i++)
		{
			exam[i]->askQuestion();
		}
	}
	int numCorrectAnswers() {
		int counter = 0;
		for (int i = 0; i < size;i++)
		{
			if (exam[i]->checkQuestion())
			{
				counter++;
			}
		}
		return counter;
	}
};