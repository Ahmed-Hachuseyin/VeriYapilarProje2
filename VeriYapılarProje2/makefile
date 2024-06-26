
derlecalistir: program calistir
program: derleme main
	g++ ./lib/Main.o ./lib/DoublyLinkedListForStack.o ./lib/DoublyLinkedListForIntegral.o ./lib/DoublyLinkedListForBinaryTree.o ./lib/BinaryTree.o ./lib/Stack.o  -o ./bin/program
derleme:
	g++ -I ./include -c ./src/BinaryTree.cpp -o ./lib/BinaryTree.o
	g++ -I ./include -c ./src/DoublyLinkedListForBinaryTree.cpp -o ./lib/DoublyLinkedListForBinaryTree.o
	g++ -I ./include -c ./src/DoublyLinkedListForIntegral.cpp -o ./lib/DoublyLinkedListForIntegral.o
	g++ -I ./include -c ./src/DoublyLinkedListForStack.cpp -o ./lib/DoublyLinkedListForStack.o
	g++ -I ./include -c ./src/Stack.cpp -o ./lib/Stack.o
	

main:
	g++ -I ./include -c ./src/main.cpp -o ./lib/main.o

calistir:	
	./bin/program.exe