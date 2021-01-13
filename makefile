p7: main.o W_Node.o Dictionary.o
        g++ -o p7 -std=c++11 main.o W_Node.o Dictionary.o

main.o: main.cpp W_Node.h Dictionary.h
        g++ -c -std=c++11 main.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
        g++ -c -std=c++11 Dictionary.cpp

clean:
        rm -f timetest *.o*~

