//类模板应用举例
#include<iostream>
#include<vector>

template <typename T>
class Stack{
    private:
        std::vector<T> elements;
    
    public:
        void push(const T& element){
            elements.push_back(element);
        }

        T pop(){
            if(elements.empty()){
                std::cerr<<"Error: Stack is empty."<<std::endl;
                exit(EXIT_FAILURE);
            }
            
            T top=elements.back();
            elements.pop_back();
            return top;
        }
        
        T top() const{
            if(elements.empty()){
                std::cerr<<"Error: Stack is empty."<<std::endl;
                exit(EXIT_FAILURE);
            }
            
            return elements.back();
        }
        
        bool isRmpty() const{
            return elements.empty();
        }
};

int main(){
    Stack<int> intStack;
    
    intStack.push(42);
    intStack.push(7);
    intStack.push(22);

    std::cout<<"Top element: "<<intStack.top()<<std::endl;
    intStack.pop();

    std::cout<<"Top element after top: "<<intStack.top()<<std::endl;
    
    return 0;
}