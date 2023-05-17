//--------------------------
// Mètodes privats auxiliars
//--------------------------

template <typename T>
void BST<T>::clear(Item *node) {
	if (node != NULL) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

template <typename T>
typename BST<T>::Item* BST<T>::insert(Item *node, const T& d) {
	if (node == NULL) {
		node = new Item(d, NULL, NULL);
	} else if (d < node->data) {
		node->left = insert(node->left, d);
	} else {
		node->right = insert(node->right, d);
	}
	return node;
}

template <typename T>
typename BST<T>::Item* BST<T>::remove(Item *node, const T& d) {
	if (node == NULL) {
		return NULL;
	} else if (d > node->data) {
		node->right = remove(node->right, d);
	} else if (d < node->data) {
		node->left = remove(node->left, d);
	} else if (node->left != NULL and node->right != NULL) {
		// Node has two children
		Item *tmp = node->right;
		while (tmp->left != NULL) {
			tmp = tmp->left;
		}
		node->data = tmp->data;
		node->right = remove(node->right, node->data);
	} else {
		// Node has at most one child
		Item *tmp = node;
		if (node->left == NULL) {
			node = node->right;
		} else if (node->right == NULL) {
			node = node->left;
		}
		delete tmp;
	}
	return node;
}

template <typename T>
void BST<T>::setValue(Item *node, const T& d, const T& value) {
	Item *temp = find(node, d);
	if (temp != NULL) {
		temp->data = value;
	} else {
		cerr << "Error: Node not found!" << endl;
	}
}


//-------------
// Constructors
//-------------

template <typename T>
BST<T>::BST() {
	root = NULL;
}


//-------------
// Destructor
//-------------

template <typename T>
BST<T>::~BST() {
	clear(root);
}


//-------------
// Modificadors
//-------------

template <typename T>
void BST<T>::insert(const T& d) {
	root = insert(root, d);
}

template <typename T>
void BST<T>::remove(const T& d) {
	root = remove(root, d);
}

template <typename T>
void BST<T>::setValue(const T& d, const T& value) {
	setValue(root, d, value);
}


//-----------
// Consultors
//-----------

template <typename T>

pair<bool, T> BST<T>::find(const T& d, Item* pitem) const
{
	if (pitem == NULL) return make_pair(false, NULL);
	if (pitem->data == d) return make_pair(true, pitem->data);
	if (pitem->left != NULL and pitem->data > d) return find(d, pitem->left);
	if (pitem->right != NULL and pitem->data < d) return find(d, pitem->right);
	return make_pair(false, NULL);
}

template <typename T>

pair<bool, T> BST<T>::find(const T& d) const {
	return find(d, root);
}
