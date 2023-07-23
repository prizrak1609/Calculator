#include "Parser.h"

#include <sstream>
#include <iostream>

#include "Object.h"
#include "Storage.h"

using namespace std;

int Parser::eval(string text)
{
    vector<string> items = split(text);
    vector<Object> converted;
    for (const string& item : items) {
        int number = std::atoi(item.data());
        if (number != 0) {
            converted.push_back({Object::Type::Number, number});
        }
        else {
            Object::Type operation;
            switch (*item.data()) {
            case '+': operation = Object::Type::OperationPlus; break;
            case '-': operation = Object::Type::OperationMinus; break;
            case '*': operation = Object::Type::OperationMultiply; break;
            case '/': operation = Object::Type::OperationDivide; break;
            default: return 0;
            }
            converted.push_back({operation, 0});
        }
    }

    IStorage* storage = Storage::getInstance();
    storage->store(converted);

    vector<Object> expression;
    int result = 0;
    while(true) {
        expression = storage->getExpression();
        if (expression.size() == 1) {
            return expression[0].getNumber();
        }
        if (expression.size() != 3) {
            std::cout << "storage->getExpression() returned expression with size " << expression.size() << std::endl;
            break;
        }
        switch (expression[1].getType()) {
        case Object::Type::OperationPlus: result = expression[0].getNumber() + expression[2].getNumber(); break;
        case Object::Type::OperationMinus: result = expression[0].getNumber() - expression[2].getNumber(); break;
        case Object::Type::OperationMultiply: result = expression[0].getNumber() * expression[2].getNumber(); break;
        case Object::Type::OperationDivide: result = expression[0].getNumber() / expression[2].getNumber(); break;
        }
        storage->replace(expression, result);
    }
    return 0;
}

vector<string> Parser::split(string text)
{
    vector<string> result;
    istringstream iss(text);
    string s;
    while (getline(iss, s, ' ')) {
        result.push_back(s);
    }
    return result;
}
