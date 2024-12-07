#include<iostream>
#include<vector>
using namespace std;
template <class ItemType>
void Swap(ItemType& a, ItemType& b) {
    ItemType temp = a;
    a = b;
    b = temp;
}
class date
{
public:
    int day;
    int month;
    int year;
    date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    date(int a,int b,int c):day(a),month(b),year(c){}
    bool operator>(const date& other) const 
    {
        if (year != other.year) {
            return year > other.year;
        }
        if (month != other.month) {
            return month > other.month;
        }
        return day > other.day;
    }
    bool operator<(const date& other) const
    {
        return other > *this;
    }
    bool operator==(const date& other) const
    {
        return (day == other.day && month == other.month && year == other.year);
    }
    bool operator<=(const date& other) const {
        return !(*this > other); // Reuse the > operator
    }
    void operator = (const date& other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    // Overload the >= operator
    bool operator>=(const date& other) const {
        return !(*this < other); // Reuse the < operator
    }
    int GetDayDifference(date r)
    {
        int tempi = 0;
        tempi += r.day - day;
        tempi += (r.month - month) * 30;
        tempi += (r.year - year) * 365;
        return tempi;
    }
};
//heap begin
date today(15, 1, 2024);
class Heap {
public:
    class node
    {
    public:
        int user_id;
        date request_date;
        node()
        {
            user_id = 0;
        }
        node(int a, int b,int c,int d) : user_id(a), request_date(b,c,d) {}
    };
    node* elements;
    int total_items;
    int capacity;
    Heap()
    {
        elements = 0;
        total_items = 0;
        capacity = 20;
        elements = new node[20];
    }
    void PrintHeap()
    {
        for (int i = 0; i < total_items; i++)
        {
            cout << elements->user_id << "\t";
            cout << elements->request_date.day << "/" << elements->request_date.month << "/" << elements->request_date.year << "/";

        }
    }
    void ReheapDown(int root, int bottom)
    {
        int maxChild, rightChild, leftChild;
        leftChild = 2 * root + 1;
        rightChild = 2 * root + 2;
        if (leftChild <= bottom) { // left child is part of the heap

            if (leftChild == bottom) // only one child
                maxChild = leftChild;
            else
            {

                if (elements[leftChild].request_date <= elements[rightChild].request_date)

                    maxChild = rightChild;

                else

                    maxChild = leftChild;

            }

            if (elements[root].request_date < elements[maxChild].request_date) {

                Swap(root, maxChild);

                ReheapDown(maxChild, bottom);

            }

        }

    }
    void ReheapUp(int root, int bottom)
    {
        int parent;
        if (bottom > root) { // tree is not empty

            parent = (bottom - 1) / 2;

            if (elements[parent].request_date > elements[bottom].request_date) {

                Swap(parent, bottom);

                ReheapUp(root, parent);

            }

        }

    }
};
// heap end
//AVL Begin
class AVL
{
public:
    class TreeNode
    {
     public:
         class borrowed
         {
         public:
             int book_id;
             date borrow_date;
             borrowed()
             {
                 book_id = 0;
             }
         };
        int User_ID;
        string name;
        borrowed* list_borrowed;
        int borrowed_count;
        int fine;
        int height;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val, string b) : User_ID(val), name(b),list_borrowed(new borrowed [20]), fine(0), height(0), left(nullptr), right(nullptr), borrowed_count(0) {}
        int getuser() { return User_ID; }
        void setuser(int val) { User_ID = val; }
        int getHeight() { return height; }
        void setHeight(int h) { height = h; }
        TreeNode* getLeft() { return left; }
        void setLeft(TreeNode* node) { left = node; }
        TreeNode* getRight() { return right; }
        void setRight(TreeNode* node) { right = node; }
    };
    TreeNode* root;
    AVL()
    {
        root = 0;
    }
    int Max(int a, int b) {
        return (a > b) ? a : b;
    }
    int height(TreeNode* node) {
        return (node != nullptr) ? node->getHeight() : -1;
    }
    TreeNode* singleRightRotate(TreeNode* k2) {
        if (k2 == nullptr)
            return nullptr;

        TreeNode* k1 = k2->getLeft();
        k2->setLeft(k1->getRight());
        k1->setRight(k2);
        k2->setHeight(Max(height(k2->getLeft()), height(k2->getRight())) + 1);
        k1->setHeight(Max(height(k1->getLeft()), height(k2)) + 1);

        return k1;
    }
    TreeNode* singleLeftRotate(TreeNode* k2) {
        if (k2 == nullptr)
            return nullptr;

        TreeNode* k1 = k2->getRight();
        k2->setRight(k1->getLeft());
        k1->setLeft(k2);
        k2->setHeight(Max(height(k2->getLeft()), height(k2->getRight())) + 1);
        k1->setHeight(Max(height(k1->getRight()), height(k2)) + 1);

        return k1;
    }
    TreeNode* doubleLeftRightRotate(TreeNode* k3) {
        k3->setLeft(singleLeftRotate(k3->getLeft()));
        return singleRightRotate(k3);
    }
    TreeNode* doubleRightLeftRotate(TreeNode* k1) {
        k1->setRight(singleRightRotate(k1->getRight()));
        return singleLeftRotate(k1);
    }
    TreeNode* avlInsert(TreeNode* root, int info) {
        if (root == nullptr)
        {
            string n;
            cout << "Enter User Name :\t";
            cin >> n;
            return new TreeNode(info, n);
        }
        if (info < root->getuser()) {
            root->setLeft(avlInsert(root->getLeft(), info));

            int htdiff = height(root->getLeft()) - height(root->getRight());
            if (htdiff == 2) {
                if (info < root->getLeft()->getuser()) {
                    root = singleRightRotate(root);
                }
                else {
                    root = doubleLeftRightRotate(root);
                }
            }
        }
        else if (info > root->getuser()) {
            root->setRight(avlInsert(root->getRight(), info));
            int htdiff = height(root->getRight()) - height(root->getLeft());
            if (htdiff == 2) {
                if (info > root->getRight()->getuser()) {
                    root = singleLeftRotate(root);  // Right-Right Case
                }
                else {
                    root = doubleRightLeftRotate(root);  // Right-Left Case
                }
            }
        }
        root->setHeight(Max(height(root->getLeft()), height(root->getRight())) + 1);
        return root;
    }
    void Insert_User()
    {
        int id = 0;
        cout << "Enter User_ID :\t";
        cin >> id;
        root = avlInsert(root, id);
    }
    void inOrder()
    {
        inOrder(root);
    }
    void inOrder(TreeNode* root) {
        if (root == nullptr)
            return;

        inOrder(root->getLeft());
        cout << "\n---------------------------------------------------------------------------------------------\n";
        cout << "User ID: " << root->getuser() << ", Name :" << root->name <<", Fine : $"<<root->fine << endl;
        if (root->borrowed_count != 0)
        {
            cout << "Books Borrowed :\n";
            for (int i = 0; i < root->borrowed_count; i++)
            {
                cout << i + 1 << ". Name : " << root->list_borrowed->book_id << ", borrow date :" << root->list_borrowed->borrow_date.day << "/" << root->list_borrowed->borrow_date.month << "/" << root->list_borrowed->borrow_date.year << endl;
            }
        }
        inOrder(root->getRight());
    }
    void PrintUser(TreeNode* root) {
        cout << "\n---------------------------------------------------------------------------------------------\n";
        cout << "User ID: " << root->getuser() << ", Name :" << root->name << ", Fine : $" << root->fine << endl;
        if (root->borrowed_count != 0)
        {
            cout << "Books Borrowed :\n";
            for (int i = 0; i < root->borrowed_count; i++)
            {
                cout << i + 1 << ". Book ID : " << root->list_borrowed->book_id << endl;
            }
        }
    }
    void addborrowed(TreeNode* &node,int c,date r)
    {
        if (node)
        {
            node->list_borrowed[node->borrowed_count].book_id = c;
            node->list_borrowed[node->borrowed_count].borrow_date = r;
            node->borrowed_count++;
                
        }
    }
    TreeNode* search(TreeNode* node, int d)
    {
        if (node)
        {
            if (node->getuser() > d)
                search(node->getLeft(), d);
            else if (node->getuser() < d)
                search(node->getRight(), d);
            else
                return node;
        }
        else
            return 0;
    };
    TreeNode* search(int d)
    {
        return search(root, d);
    }
};
// Avl out
// BST begin
class Node {
public:
    int ISSN;
    string title;
    vector<string> authors;
    int reference_copies;
    int issuable_copies;
    Heap user_requests;
    Node* left;
    Node* right;
    Node()
    {
        string temp;// for storing authors.
        string temp2;
        left = 0;
        right = 0;
        cout << "\nISSN :\t";
        cin >> ISSN;
        cout << "\nTitle :\t";
        cin >> title;
        cout << "\nAuthors :\t";
        cin >> temp;
        for (int i = 0, j = 0; temp[i] != '\0'; i++)
        {
            if (temp[i] == ',' || temp[i + 1] == '\0')
            {
                temp2[j] = '\0';
                j = 0;
                authors.push_back(temp2);
                temp2 = "\0";
            }
            else
            {
                temp2[j] = temp[i];
                j++;
            }
        }
        cout << "\nReference copies :\t";
        cin >> reference_copies;
        cout << "\nIssuable copies :\t";
        cin >> issuable_copies;
        cout << "Book added ISSN : " << ISSN << " Title : " << title << endl;

    };
    Node(int d)
    {
        string temp;// for storing authors.
        string temp2;
        left = 0;
        right = 0;
        this->ISSN = d;
        cout << "\nTitle :\t";
        cin >> title;
        cout << "\nAuthors :\t";
        cin >> temp;
        for (int i = 0, j = 0; temp[i] != '\0'; i++)
        {
            if (temp[i] == ',' || temp[i] == '\0')
            {
                j = 0;
                authors.push_back(temp2);
                temp2.clear();
            }
            else
            {
                temp2 += temp[i];
                j++;
            }
        }
        authors.push_back(temp2);
        temp2.clear();
        cout << "\nReference copies :\t";
        cin >> reference_copies;
        cout << "\nIssuable copies :\t";
        cin >> issuable_copies;
        cout << "Book added ISSN : " << ISSN << " Title : " << title << endl;
    };
};
class tree {
public:
    Node* root;
public:
    tree()
    {
        root = nullptr;
    };
    void inOrder(Node* iterator)
    {
        if (iterator) {
            inOrder(iterator->left);
            Print_node(iterator);
            inOrder(iterator->right);
        }
    };
    void inOrder() { inOrder(root); }
    void insertR(int d, Node*& node)
    {
        if (node == NULL) {
            node = new Node(d);
        }
        else if (node->ISSN > d)
            insertR(d, node->left);
        else
            insertR(d, node->right);
    }
    void insertR()
    {
        int d = 0;
        cout << "\nEnter ISSN number :\t";
        cin >> d;
        insertR(d, root);
    }
    void Print_node(Node* ptr)
    {
        cout << "\n-------------------------------------------------------------------------\n";
        cout << "ISSN : " << ptr->ISSN << endl;
        cout << "Title : " << ptr->title << endl;
        for (int i = 0; i < ptr->authors.size(); i++)
        {
            cout << "Author " << i+1 << " : " << ptr->authors[i] << endl; //have to accomodate the printing of whole array.
        }
        cout << "Reference Copies: " << ptr->reference_copies << endl;
        cout << "Issuable Copies : " << ptr->issuable_copies << endl;
    }
    Node* searchR(Node* node, int d)
    {
        if (node) 
        {
            if (node->ISSN > d)
                searchR(node->left, d);
            else if (node->ISSN < d)
                searchR(node->right, d);
            else
                return node;
        }
        else
            return 0;
    };
    Node* searchR(int d)
    { 
        return searchR(root, d);
    }
    void deleteR(int d) { deleteR(d, root); }
    void deleteR(int d, Node*& node)
    {
        if (d > node->ISSN)
            deleteR(d, node->right);
        else if (d < node->ISSN)
            deleteR(d, node->left);
        else
            deleteNode(node);
    }
    void deleteNode(Node*& node)
    {
        int d;
        Node* temp;
        temp = node;
        if (node->left == NULL) {
            node = node->right;
            delete temp;
        }
        else if (node->right == NULL) {
            node = node->left;
            delete temp;
        }
        else
        {
            getPredecessor(node->left, d);
            node->ISSN = d;
            deleteR(d, node->left);
        }
    }
    void getPredecessor(Node* node, int& d)
    {
        if (d > node->ISSN)
            deleteR(d, node->right);
        else if (d < node->ISSN)
            deleteR(d, node->left);
        else
            deleteNode(node);
    }
    void Destroy(Node*& node)
    {
        if (node) {
            Destroy(node->left);
            Destroy(node->right);
            delete node;
        }
    }
    ~tree() { Destroy(root); }
};
//BST end
class LibraryManagementSystem
{
public:
    tree Booklist;
    AVL user;
    void Borrow_Book(int d)
    {
        Borrow_Book(Booklist.root, d);
    }
    void Borrow_Book(Node* bok, int d)
    {
        if (bok)
        {
            if (bok->ISSN > d)
                Borrow_Book(bok->left, d);
            else if (bok->ISSN < d)
                Borrow_Book(bok->right, d);
            else
            {
                cout << "Book found with ISSN : " << bok->ISSN << endl;
                if (bok->issuable_copies != 0)
                {
                    int temp_id = 0;
                    cout << "\nEnter the user id to issue copy to :\t";
                    cin >> temp_id;
                    if (user.search(temp_id) != 0)
                    {
                        cout << "\nEnter the request date :\t";
                        cin >> bok->user_requests.elements[bok->user_requests.total_items].request_date.day;
                        cin >> bok->user_requests.elements[bok->user_requests.total_items].request_date.month;
                        cin >> bok->user_requests.elements[bok->user_requests.total_items].request_date.year;
                        bok->user_requests.elements->user_id = temp_id;
                        AVL::TreeNode* r = user.search(temp_id);
                        user.addborrowed(r, bok->ISSN,bok->user_requests.elements->request_date);
                        bok->user_requests.ReheapUp(0, bok->user_requests.total_items);
                        bok->issuable_copies--;
                    }
                    else
                    {
                        cout << "\nIncorrect user id entered\n";
                    }
                }
                else
                {
                    int temp_id = 0;
                    cout << "\nEnter the user id to issue copy to :\t";
                    cin >> temp_id;
                    if (user.search(temp_id)!=0)
                    {
                        cout << "\nEnter the request date :\t";
                        cin >> bok->user_requests.elements[bok->user_requests.total_items].request_date.day;
                        cin >> bok->user_requests.elements[bok->user_requests.total_items].request_date.month;
                        cin >> bok->user_requests.elements[bok->user_requests.total_items].request_date.year;
                        bok->user_requests.elements->user_id = temp_id;
                        bok->user_requests.ReheapUp(0, bok->user_requests.total_items);
                        bok->user_requests.total_items++;
                    }
                    else
                    {
                        cout << "\nIncorrect user id entered\n";
                    }
                }
            }
        }
        else
            cout << "\nBook not found!!!\n";

    }
    void return_Book(int d)
    {
        return_Book(user.root, d);
    }
    void return_Book(AVL::TreeNode* bok, int d)
    {
        if (bok)
        {
            if (bok->User_ID > d)
                return_Book(bok->left, d);
            else if (bok->User_ID < d)
                return_Book(bok->right, d);
            else
            {
                int temp_issn = 0;
                cout << "\nUser Found\nEnter the book ISSN :\t";
                cin >> temp_issn;
                Node* temp_book = Booklist.searchR(temp_issn);
                if (temp_book)
                {
                    int i;
                    int flag = false;
                    for (i = 0; i < bok->borrowed_count; i++)
                    {
                        if (bok->list_borrowed[i].book_id == temp_issn)
                        {
                            int days = bok->list_borrowed[i].borrow_date.GetDayDifference(today);
                            int fineDays = days - 10;
                            if (fineDays > 0)
                            {
                                bok->fine += fineDays * 1;
                            }
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                    {
                        for (int j = i + 1; j < bok->borrowed_count; j++, i++)
                        {
                            bok->list_borrowed[i].book_id = bok->list_borrowed[j].book_id;
                            bok->list_borrowed[i].borrow_date = bok->list_borrowed[j].borrow_date;
                        }
                        bok->borrowed_count--;
                        temp_book->issuable_copies++;
                    }
                    if (temp_book->user_requests.total_items > 0)
                    {
                        int id = temp_book->user_requests.elements[0].user_id;
                        date is = temp_book->user_requests.elements[0].request_date;
                        temp_book->user_requests.elements[0] = temp_book->user_requests.elements[temp_book->user_requests.total_items - 1];
                        temp_book->user_requests.total_items--;
                        temp_book->user_requests.ReheapDown(0, temp_book->user_requests.total_items - 1);
                        AVL::TreeNode* r = user.search(id);
                        user.addborrowed(r, bok->User_ID,is);
                        temp_book->issuable_copies--;
                    }
                }
            }
        }
    

    }
    void change_Attributes()
    {
        int a = 0;
        cout << "Enter the ISSN of the book\n";
        cin >> a;
        change_Attributes(Booklist.root,a);
        
    }
    void change_Attributes(Node* bok,int d)
    {
        if (bok)
        {
            if (bok->ISSN > d)
                Borrow_Book(bok->left, d);
            else if (bok->ISSN < d)
                Borrow_Book(bok->right, d);
            else
            {
                int choice2 = 0;
                cout << "What do you want to change?\n1. Title\n2. Authors\n3. Reference Copies\n4. Issuable copies\n ";
                cin >> choice2;
                while (1)
                {
                    if (choice2 == 1)
                    {
                        cout << "Current Title :\t" << bok->title;
                        cout << "New Title :\t";
                        cin >> bok->title;
                    }
                    else if (choice2 == 2)
                    {
                        cout << "Current Authors :\t";
                        for (int i = 0; i < bok->authors.size(); i++)
                        {
                            cout << i + 1 << bok->authors[i];
                        }
                        int i = 0;
                        cout << "New author Number :\t";
                        cin >> i;
                        cout << "Author Name :\t";
                        cin >> bok->authors[i - 1];
                    }
                    else if (choice2 == 3)
                    {
                        cout << "Current Reference Copies :\t" << bok->reference_copies;
                        cout << "New Number of Reference copies :\t";
                        cin >> bok->reference_copies;
                    }
                    else if (choice2 == 4)
                    {
                        cout << "Current Issuable Copies :\t" << bok->issuable_copies;
                        cout << "New number of Issuable copies:\t";
                        cin >> bok->issuable_copies;
                        while (bok->issuable_copies > 0)
                        {
                            if (bok->user_requests.total_items > 0)
                            {
                                int id = bok->user_requests.elements[0].user_id;
                                date is = bok->user_requests.elements[0].request_date;
                                bok->user_requests.elements[0] = bok->user_requests.elements[bok->user_requests.total_items - 1];
                                bok->user_requests.total_items--;
                                bok->user_requests.ReheapDown(0, bok->user_requests.total_items - 1);
                                AVL::TreeNode* r = user.search(id);
                                user.addborrowed(r, bok->user_requests.elements[0].user_id, is);
                                bok->issuable_copies--;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    void delete_book(int d)
    {
        Booklist.deleteR(d);
        int temp_issn = 0;
        cout << "\nbook Found\nEnter the User ID :\t";
        cin >> temp_issn;
        AVL::TreeNode* user1 = user.search(temp_issn);
        if (user1)
        {
            int i;
            int flag = false;
            for (i = 0; i < user1->borrowed_count; i++)
            {
                if (user1->list_borrowed[i].book_id == d)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                for (int j = i + 1; j < user1->borrowed_count; j++, i++)
                {
                    user1->list_borrowed[i].book_id = user1->list_borrowed[j].book_id;
                    user1->list_borrowed[i].borrow_date = user1->list_borrowed[j].borrow_date;
                }
                user1->borrowed_count--;
            }
        }
        else
        {
            cout << "\nNO user Found\n";
        }
    }
    void Most_Requested(Node* iterator,Node* &pp,int &d)
    {
        if (iterator) {
            Most_Requested(iterator->left,pp,d);
            //Print_node(iterator);
            if (iterator->user_requests.total_items > d)
            {
                d = iterator->user_requests.total_items;
                pp = iterator;
            }
            Most_Requested(iterator->right,pp,d);
        }
    }
    void calculate_fines(AVL::TreeNode* root)
    {
        if (root == nullptr)
            return;

        calculate_fines(root->getLeft());
        for (int i = 0; i < root->borrowed_count; i++)
        {
            int days = root->list_borrowed[i].borrow_date.GetDayDifference(today);
            int fineDays = days - 10;
            if (fineDays > 0)
            {
                root->fine += fineDays * 1;
            }
        }
        calculate_fines(root->getRight());
    }
    void display_fines1(AVL::TreeNode* root)
    {
        if (root == nullptr)
            return;

        display_fines1(root->getLeft());
        if (root->fine != 0)
        {
            cout << "User ID : " << root->User_ID << ", Fine : $" << root->fine << endl;
        }
        display_fines1(root->getRight());
    }
    void display_fines2(AVL::TreeNode* root)
    {
        if (root == nullptr)
            return;

        display_fines2(root->getLeft());
        if (root->fine == 0)
        {
            cout << root->User_ID;
        }
        display_fines2(root->getRight());
    }
    void run()
    {
        int choice = 0;
        while (1)
        {
            cout << "\nEnter your choice:\n1. Enter a New Book\n2. Enter a New user\n3. Borrow a Book\n4. Return a book\n5. Change Attributes of a book\n6. Delete a book\n7. Most Demanded book\n8. User details\n9. Calculate fines\n0. Display All Books and user Lists\n";
            cin >> choice;
            if (choice == 1)
            {
                Booklist.insertR();
                continue;
            }
            else if (choice == 2)
            {
                user.Insert_User();
                continue;
            }
            else if (choice == 3)
            {
                int tempISSN;
                cout << "\nEnter the ISSN of the Book :\t";
                cin >> tempISSN;
                Borrow_Book(tempISSN);
            }
            else if (choice == 4)
            {
                int tempISSN;
                cout << "\nEnter the ID of the user :\t";
                cin >> tempISSN;
                return_Book(tempISSN);
            }
            else if (choice == 5)
            {
                change_Attributes();
            }
            else if (choice == 6)
            {
                int tempISSN;
                cout << "\nEnter the ISSN of the Book :\t";
                cin >> tempISSN;
                delete_book(tempISSN);
            }
            else if (choice == 7)
            {
                Node* pp = 0;
                int count = 0;
                Most_Requested(Booklist.root, pp, count);
                cout << "Most Demanded book is : " << pp->title << ", With total demands of " << count << endl;
            }
            else if (choice == 8)
            {
                int tempISSN;
                cout << "\nEnter the ID of the user :\t";
                cin >> tempISSN;
                AVL::TreeNode* a = user.search(tempISSN);
                user.PrintUser(a);
            }
            else if (choice == 9)
            {
                calculate_fines(user.root);
                display_fines1(user.root);
                cout << "No fines for User : ";
                display_fines2(user.root);
            }
            else if (choice == 0)
            {
                Booklist.inOrder();
                user.inOrder();
            }
        }
        
    }
};

int main()
{
    LibraryManagementSystem driver;
    driver.run();
    system("pause");
	return 0;
}