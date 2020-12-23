// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <vld.h>


typedef struct t_node {
	int key;
	struct t_node* left;
	struct t_node* right;

} Node, * Tree;

Tree init_tree() { return NULL; }

Tree create_node(int key, Node* left, Node* right) {
	Tree root;
	root = (Node*)malloc(sizeof(Node));
	root->key = key;
	root->left = left;
	root->right = right;
	return root;
}

void add_node(int key, Tree& root) {
	if (root == NULL)
		root = create_node(key, NULL, NULL);
	else if (key > root->key) {
		add_node(key, root->right);
	}
	else if (key < root->key) {
		add_node(key, root->left);
	}
}

void print_node(Tree& root) 
{
	if (root->left != NULL) {
		print_node(root->left);
	}

	std::cout << root->key << std::endl;

	if (root->right != NULL) {
		print_node(root->right);
	}
}

bool elem_exist = false;
void find_elem(int key, Tree& root) 
{
	if (root != NULL) {
		if (key > root->key)
		{
			std::cout << "Value = " << key << " > " << root->key << std::endl;
			find_elem(key, root->right);
		}
		else if (key < root->key)
		{
			std::cout << "Value = " << key << " < " << root->key << std::endl;
			find_elem(key, root->left);
		}
		else
		{
			elem_exist = true;
			return;
		}
	}
}

void exist_elem(int key, Tree& root) 
{
	find_elem(key, root);

	std::cout << elem_exist << std::endl;
}

void delete_tree(Tree& root) 
{
	std::cout << "Start delete element: " << root->key << std::endl;

	if (root->left != NULL)
		delete_tree(root->left);

	if (root->right != NULL)
		delete_tree(root->right);

	if (root->left != NULL) {
		std::cout << "Delete: " << root->key << std::endl;
		delete root->left;
		root->left = NULL;
	}

	if (root->right != NULL) {
		std::cout << "Delete: " << root->key << std::endl;
		delete root->right;
		root->right = NULL;
	}
}

int main()
{
	//int* arr = (int*)malloc(100000);
	//free(arr);

	/*Tree tree = (Tree)malloc(sizeof(Tree));

	free(tree);*/
	//free(tree);

	std::cout << "Input lenght: ";
	int lenght = 0;
	std::cin >> lenght;

	Tree tree = NULL;

	for (int i = 0; i < lenght; i++) 
	{
		std::cout << i + 1 << ") Input value: ";
		int value = 0;
		std::cin >> value;
		add_node(value, tree);
	}

	print_node(tree);
	/*std::cout << tree->key << std::endl;
	std::cout << tree->left->key << std::endl;
	std::cout << tree->right->key << std::endl;*/

	std::cout << "Search element: ";
	int value = 0;
	std::cin >> value;

	exist_elem(value, tree);
	delete_tree(tree);
	delete tree;
	std::cin.get();
}
