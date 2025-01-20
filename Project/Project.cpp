//Project.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;


struct verteses_state;      //forward declaration
struct edges_classUN;       //forward declaration


//help: use ctrl+leftClick shortcut on the function to get teleported to the function body(if using visual studio community).
//functions bodies are available after the main() method


//linked lists structure
struct node {            

    int data;                    //"data" is the value that the vertex hold

    int AdjacencyListVertexID;   //the vertex identefier in the linked list for immediate acces to the head using this variable

    std::string nState;          //node state

    node* next;                  //next node pointer

    node* headParent;            //this member of every node stores the head of the linked list containing this node

    node();
    ~node();
};

//__________________________________________________

//stack structure
struct stack {
    int* st = NULL;
    int size;
    int top;

    stack(int size);
    ~stack();
    void push(int element);
    int pop();

    int getTop();
    void showTop();
    bool isEmpty() {
        return top == -1;
    }

    bool exsist(int e);
};

//__________________________________________________

//this dataType represents the graph and its behaviour(Methods) wich oriants it to satisfy our needs in this project
class graph {                           
public:
    int graphSize;

//an array that keeps all of the vertices values in the graph(just vertices without any connections)
    int Vertices[10];             


    int AdjacencyMatrix[10][10];

/*an array of linkes lists heads, that each head represents a vertix, and each head is the starting
 point of a linked list representing the connections of a vertex*/
    node* AdjacencyList[1005] = { NULL };  
    node* tranposedAdjacencyList[1005] = { NULL };

//Cheriyan Mehlhorn Gabow member variables
    stack* oStack = NULL;
    stack* rStack = NULL;
    int comp[1005] = { NULL };

//Adjacencey Array Container Variables
    int AdjacencyVerticesArray[11];
    int AdjacencyEdgesArray[100];

//boolean values to control the program flow
    bool representedAsAdjacencyMatrix,
        representedAsAdjacencyList,
        representedAsTransposedAdjacencyList,
        matrixTransposed,
        representedAsAdjacencyArray,
        dataSetInput;


public:

/*Constructors:
VERY IMPORTANT NOTE!!!!
if you want to input a dataSet provide the path of the (.txt) file in the constructor
    ex: graph g(1005,"this is a file path")
if you want to run the program without a dataSet just provide the graph size
    ex: graph g(7)

if you decide to use a dataSet then its only possible to use limited amount of functions in this project
beacuse handling big data such as 1000 vertecese is causes memory problems*/


    graph(int graphSize = 1005, string filepath = "NULL");
    graph(string filepath);
    ~graph();

//Function prototype for displaying vertaeces
    void displayVerteses();

//Function prototype for Adjacencey Matrix Methods:
    void representAsAdjacencyMatrix();             
    void representAsAdjacencyMatrixUnDir();         
    void transopseAdjacencyMatrix();                
    void displayAdjacencyMatrix();

//Function prototype for Adjacencey List Methods:
    void representAsAdjacencyList();              
    void representAsAdjacencyListNoSelfLoops();     
    void transposeAdjacencyList();                                
    void displayAdjacencyList();
    void displayTransposedAdjacencyList();

//Function prototype for Adjacencey Array Methods:
    void representAsAdjacencyArray();               
    void displayAdjacencyArray();

//Function prototype for testing Strong Connectivity using linked list or matrix
    bool isStronglyConnected_ListDfs(verteses_state& vs);  
    bool isStronglyConnected_MatDfs(verteses_state& vs);   

//Function prototype for Cheriyan Mehlhorn Gabow Methods
    void displayComp();

//Function prototype for JensSchmidt
    void DFS_JensSchmidt(int vertex, graph& g, verteses_state& vs, int parent[], int& dfs_counter, int low[], int bridges[][2], int& bridge_count, int cut_vertices[], int& cut_vertex_count);

//Function prototype for website DataSet input 
    void addnodeToList(node* head, node* newNode);
    void representAsAdjacencyListUsingDataSet(string filepath);
};



//__________________________________________________


struct verteses_state {
    std::string* state[1005];
    int* dfs_num[1005];
    int* finish_num[1005];
    int dfs_counter;
    int finish_counter;
    int graphSize;

    verteses_state(int graphSize);
    void init(graph& g);
    void display_versteses_states();
    void display_versteses_dfsnum();
    void display_versteses_fnum();
};

//__________________________________________________

//Function prototype for depth first search methods (DFS):

void DFS_Mat(int vertex, graph& g, verteses_state& v);               //uses adjacencey matrix

void DFS_Undirected(int vertex, graph& g, verteses_state& vs, int TE[][2], int& TE_count, int BE[][2], int& BE_count);// a DFS for undirected graphs

void DFS_List(int vertex, graph& g, verteses_state& vs);             //uses linked list

void DFS_TransposedList(int vertex, graph& g, verteses_state& vs);   //a DFS for transposed linked list 

void DepthFirstSearch(graph g, verteses_state& v);  //uses linked list if represented as linked list and matrix if not

//__________________________________________________

//Function prototype for Cheriyan Mehlhorn Gabow Methods
void DFS_Cheriyan_Mehlhorn_Gabow_List(int vertex, graph& g, verteses_state& vs); 
void Cheriyan_Mehlhorn_Gabow(graph g, verteses_state& v);                       

//_______________________###<    MAIN    >###___________________________

int main() {
    srand(time(0));     //randomizes the output for each run of the code

//                 < NOTE:                                                                                                >
//                 < In The Following There Is Ready Pre Written Blocks Of Code As Examples How This Program Works.       >
//                 < UnComment Any Block Of Code And Run The Program To See The OutPut.                                   >

//-------------------DFS ON DATASET INPUT (TAKE DATASET FILE FROM THE GITHUB REPOSOTORY)-------------------

    //graph* g = new graph(1005,<"put dataSet file path here>");
    //
    //verteses_state* v = new verteses_state(g->graphSize);
    //
    //g->displayAdjacencyList();
    //
    //DFS_List(1, *g, *v); //choose any number between 1 and 1005
    //
    //v->display_versteses_states();
    //v->display_versteses_dfsnum();
    //v->display_versteses_fnum();
    //v->init(*g);


//-------------------LINKED LIST TRANSPOSE, DFS, AND TESTING STRONG CONNECTIVITY-------------------


    //graph* g = new graph(4);  //pick any number between 1 and 10
    //
    //verteses_state* v = new verteses_state(g->graphSize);
    //
    //g->displayVerteses();
    //
    //g->representAsAdjacencyListNoSelfLoops(); //or g->representAsAdjacencyList();
    //g->displayAdjacencyList();
    //
    //DFS_List(1, *g, *v); //choose any number between 1 and 10
    //
    //v->display_versteses_states();
    //v->display_versteses_dfsnum();
    //v->display_versteses_fnum();
    //v->init(*g);
    //
    //g->transposeAdjacencyList();
    //if (g->isStronglyConnected_ListDfs(*v))
    //    cout << "Graph IS Strongly Connected\n";
    //else
    //    cout << "Graph IS Not Strongly Connected\n";
    //
    //cout << "----------------------------------------------------\n";
    //
    //
    //g->displayTransposedAdjacencyList();



//-------------------MATRIX TRANSPOSE, DFS, AND TESTING STRONG CONNECTIVITY-------------------

    //graph* g = new graph(10);  //pick any number between 1 and 10
    //
    //verteses_state* v = new verteses_state(g->graphSize);
    //
    //g->displayVerteses();
    //
    //g->representAsAdjacencyMatrix();
    //g->displayAdjacencyMatrix();
    //
    //DFS_Mat(1, *g, *v); //choose any number between 1 and 10
    //
    //v->display_versteses_states();
    //v->display_versteses_dfsnum();
    //v->display_versteses_fnum();
    //v->init(*g);
    //
    //if (g->isStronglyConnected_MatDfs(*v))
    //    cout << "Graph IS Strongly Connected\n";
    //else
    //    cout << "Graph IS Not Strongly Connected\n";
    //
    //cout << "----------------------------------------------------\n";
    //
    //g->transopseAdjacencyMatrix();
    //g->displayAdjacencyMatrix();

//-------------------ADJACENCEY ARRAY REPRESENTATION AND DISPLAYING-------------------

    //graph* g = new graph(7);  //pick any number between 1 and 10
    //
    //verteses_state* v = new verteses_state(g->graphSize);
    //
    //g->displayVerteses();
    //
    //g->representAsAdjacencyArray();
    //g->displayAdjacencyArray();


//-------------------JENS SHMIDT TEST-------------------


//    graph* g = new graph(4);  //pick any number between 1 and 10
// 
//    verteses_state* v = new verteses_state(g->graphSize);
//
//
//
////Represent the graph as an undirected adjacency matrix
//    g->representAsAdjacencyMatrixUnDir();
//    g->displayAdjacencyMatrix();
//
//    // Arrays to store parent, low numbers, bridges, and cut vertices
//    int parent[10] = { -1 }; // Parent of each vertex in DFS tree
//    int low[10] = { 0 };     // Low numbers for each vertex
//    int bridges[100][2];     // Store bridges (edges) - assuming max 100 bridges
//    int bridge_count = 0;    // Counter for bridges
//    int cut_vertices[10];    // Store cut vertices - assuming max 10 cut vertices
//    int cut_vertex_count = 0; // Counter for cut vertices
//
//    // Perform DFS and classify edges
//    int dfs_counter = 0;
//    g->DFS_JensSchmidt(1, *g, *v, parent, dfs_counter, low, bridges, bridge_count, cut_vertices, cut_vertex_count);
//
//    // Display results
//    cout << "Bridges:\n";
//    for (int i = 0; i < bridge_count; i++) {
//        cout << "(" << bridges[i][0] << ", " << bridges[i][1] << ") ";
//    }
//    cout << "\nCut Vertices:\n";
//    for (int i = 0; i < cut_vertex_count; i++) {
//        cout << cut_vertices[i] << " ";
//    }
//    cout << endl;


    return 0;
}

//                ###<   ALL FUNCTIONS BODIES   >###

node::node() {

    data = -1;

    AdjacencyListVertexID = -1;

    next = NULL;

    nState = "new";

    headParent = NULL;
}

node::~node() {
    delete next;
    delete headParent;
}

//__________________________________________________

stack::stack(int size) {

    st = new int[size];

    this->size = size;

    top = -1;
}

stack::~stack() {

    delete st;
}

void stack::push(int element) {

    if (top == size) {
        cout << "Stack OverFlow\n";
        return;
    }
    else if (top == -1) {
        top++;
        st[top] = element;
    }
    else {
        st[top] = element;
        top++;
    }
    return;
}

int stack::pop() {
    if (top == -1) {
        cout << "Stack UnderFlow\n";
        return -999;
    }
    else {
        top--;
        return st[top + 1];
    }
}

void stack::showTop() {

    if (top == -1) {
        cout << "Stack UnderFlow\n";
        return;
    }
    else {
        cout << "Top Element: " << st[top] << endl;
        return;
    }
}

int stack::getTop() {

    if (top == -1) {
        cout << "Stack UnderFlow\n";
        return -999;
    }
    else return st[top];
}

bool stack::exsist(int e) {

    for (int i = 0; i < size; i++) {
        if (st[i] == e)
            return true;
    }
    return false;
}

//__________________________________________________

graph::graph(int graphSize, string filepath) {          

    oStack = new stack(graphSize);
    rStack = new stack(graphSize);

    representedAsAdjacencyMatrix = false;
    representedAsAdjacencyList = false;
    representedAsTransposedAdjacencyList = false;
    matrixTransposed = false;
    representedAsAdjacencyArray = false;

    for (int i = 0; i < graphSize; i++) {
        comp[i] = -1;
    }

//DataSet input
    if (filepath != "NULL") {   
        representAsAdjacencyListUsingDataSet(filepath);
        this->graphSize = graphSize;
        dataSetInput = true;
        return;
    }

//None-DataSet input
    dataSetInput = false;
    if (graphSize > 10)                      //graph size more that 10 is not allowed
        this->graphSize = 10;
    else
        this->graphSize = graphSize;

    for (int i = 0; i < graphSize; i++) {    //initializing vertices array with the number of each vertex in the sequence
        Vertices[i] = i + 1;                 //EX: graphSize=3 -> vertices: 1,2,3
    }


    for (int i = graphSize; i < 10; i++)    //initializing the rest of the elements(if graphSize<10) with zeros
        Vertices[i] = 0;



    for (int i = 0; i < 100; i++) {          //initializing AdjacencyMatrix & adjecencyVerticesArray & adjecencyEdgesArraywith zeros
        AdjacencyEdgesArray[i] = 0;
        if (i >= 10)
            continue;
        AdjacencyVerticesArray[i] = -1;
        for (int j = 0; j < 10; j++) {
            AdjacencyMatrix[i][j] = 0;
        }
    }


}

graph::graph(string filepath) {
    graph(1005, filepath);

}

graph::~graph() {                         //destructor to free up the dynamically allocated AdjacencyList and tranposedAdjacencyList values
    for (int i = 0; i < 10; i++) {
        while (AdjacencyList[i] != NULL) {
            node* temp = AdjacencyList[i];
            AdjacencyList[i] = AdjacencyList[i]->next;
            delete temp;
        }
        while (tranposedAdjacencyList[i]) {
            node* temp = tranposedAdjacencyList[i];
            tranposedAdjacencyList[i] = tranposedAdjacencyList[i]->next;
            delete temp;
        }
    }
    delete oStack;
    delete rStack;
}

void graph::displayVerteses() {           //a visualized way to see the vertices list
    if (dataSetInput) {
        cout << "Operation Not Possible, The Input Is A data Set And There Is A 1005 Vertacies\n";
        return;
    }
    cout << "verteses list: ";
    for (int i = 0; i < graphSize; i++) {
        cout << Vertices[i] << ",";
    }
    cout << "\n----------------------------------------------------\n";
}

//AdjacencyMatrix methods

void graph::representAsAdjacencyMatrix() {      //setting connections to the graph randomly in the AdjacencyMatrix
    if (dataSetInput) {
        cout << "Only Linked List Operations Possible When the Input Is A DataSet!\n";
        return;
    }


    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            AdjacencyMatrix[i][j] = 0 + (rand() % (1 - 0 + 1));   //generates a random value between 0 and 1
        }
    }
    representedAsAdjacencyMatrix = true;
}
void graph::representAsAdjacencyMatrixUnDir() {      //setting connections to the graph randomly in the AdjacencyMatrix
    if (dataSetInput) {
        cout << "Only Linked List Operations Possible When the Input Is A DataSet!\n";
        return;
    }


    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            AdjacencyMatrix[i][j] = 0 + (rand() % (1 - 0 + 1));   //generates a random value between 0 and 1
        }
    }
    for (int i = 0; i < graphSize; i++)
        for (int j = 0; j < graphSize; j++)
            if (AdjacencyMatrix[i][j] == 1 && AdjacencyMatrix[j][i] == 0)
                AdjacencyMatrix[j][i] = 1;
    representedAsAdjacencyMatrix = true;
}
void graph::transopseAdjacencyMatrix() {         //turning the Adjacency matrix into it's transpose 
    if (dataSetInput) {
        cout << "Only Linked List Operations Possible When the Input Is A DataSet!\n";
        return;
    }


    for (int i = 0; i < graphSize; i++) {
        for (int j = i + 1; j < graphSize; j++) {
            AdjacencyMatrix[i][j] = AdjacencyMatrix[i][j] + AdjacencyMatrix[j][i];
            AdjacencyMatrix[j][i] = AdjacencyMatrix[i][j] - AdjacencyMatrix[j][i];
            AdjacencyMatrix[i][j] = AdjacencyMatrix[i][j] - AdjacencyMatrix[j][i];
        }
    }
    if (matrixTransposed)
        matrixTransposed = false;
    else
        matrixTransposed = true;
}
void graph::displayAdjacencyMatrix() {   //a visualized way to see the vertices connections Matrix (AdjacencyMatrix)
    if (dataSetInput) {
        cout << "Only Linked List Operations Possible When the Input Is A DataSet!\n";
        return;
    }



    if (!representedAsAdjacencyMatrix) {
        cout << "GRAPH IS NOT REPRESENTED AS Adjacency MATRIX YET!\n YOU NEED TO USE: representAsAdjacencyMatrix() FIRST\n";
        return;
    }
    if (!matrixTransposed) {
        cout << "Adjacency MATRIX:\n";
        cout << "    ";
        for (int i = 0; i < graphSize; i++) {
            cout << Vertices[i] << "  ";
        }
        cout << endl;
        for (int i = 0; i < graphSize; i++) {
            cout << Vertices[i] << ":  ";
            for (int j = 0; j < graphSize; j++) {
                cout << AdjacencyMatrix[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "_____________________________________\n";

    }
    else {
        cout << "TRANSPOSED Adjacency MATRIX:\n";
        cout << "    ";
        for (int i = 0; i < graphSize; i++) {
            cout << Vertices[i] << "  ";
        }
        cout << endl;
        for (int i = 0; i < graphSize; i++) {
            cout << Vertices[i] << ":  ";
            for (int j = 0; j < graphSize; j++) {
                cout << AdjacencyMatrix[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "_____________________________________\n";

    }
}




//AdjacencyList methods


void graph::representAsAdjacencyList() {      //setting connections to the graph randomly in the AdjacencyList
    if (dataSetInput) {
        cout << "Already Represented As Linked List!\n";
        return;
    }


    bool randomTorF = 0;
    for (int i = 0; i < graphSize; i++) {
        AdjacencyList[i] = new node();
        AdjacencyList[i]->data = Vertices[i];
        AdjacencyList[i]->AdjacencyListVertexID = i;
        AdjacencyList[i]->headParent = AdjacencyList[i];
        AdjacencyList[i]->next = NULL;
        for (int j = 0; j < graphSize; j++) {
            randomTorF = 0 + (rand() % (1 - 0 + 1));    //generates a random value between 0 and 1
            if (randomTorF) {
                node* newNode = new node();             /*this and the next 5 lines of code represents the algorithm to add an element
                                                        to the linked list, and insertion is at the beggining of the list
                                                        but right after the head node (HEAD NODE HAVE A FIXED PALCE AT BEGGINING).
                                                        (this is more efficient than insert at last as the element ordering isnt important for us)*/
                newNode->data = Vertices[j];
                newNode->AdjacencyListVertexID = j;
                newNode->next = AdjacencyList[i]->next;
                newNode->headParent = AdjacencyList[i];
                AdjacencyList[i]->next = newNode;
            }
        }
    }
    representedAsAdjacencyList = true;
}
void graph::representAsAdjacencyListNoSelfLoops() {   //setting connections to the graph randomly in the AdjacencyList but without self loops
    if (dataSetInput) {
        cout << "Already Represented As Linked List!\n";
        return;
    }


    for (int i = 0; i < graphSize; i++) {
        bool randomTorF = 0;
        AdjacencyList[i] = new node();
        AdjacencyList[i]->data = Vertices[i];
        AdjacencyList[i]->AdjacencyListVertexID = i;
        AdjacencyList[i]->next = NULL;
        for (int j = 0; j < graphSize; j++) {
            if (i == j)                                  //this line is the only deffirance between this function and the previous one
                continue;
            randomTorF = 0 + (rand() % (1 - 0 + 1));
            if (randomTorF) {
                node* newNode = new node();
                newNode->data = Vertices[j];
                newNode->AdjacencyListVertexID = j;
                newNode->next = AdjacencyList[i]->next;
                AdjacencyList[i]->next = newNode;
            }
        }
    }
    representedAsAdjacencyList = true;
}
void graph::transposeAdjacencyList() {           //finding the transpose for the Adjacency List
    if (!representedAsAdjacencyList) {
        cout << "YOU CAN'T TRANSPOSE THE Adjacency LIST YET!\nYOU NEED TO REPRESENT THE GRAPH AS Adjacency LIST!\nUSE: representAsAdjacencyList() OR  representAsAdjacencyListNoSelfLoops() FIRST\n";
    }


    for (int i = 0; i < graphSize; i++) {

        tranposedAdjacencyList[i] = new node();
        tranposedAdjacencyList[i]->data = Vertices[i];
        tranposedAdjacencyList[i]->AdjacencyListVertexID = i;
        tranposedAdjacencyList[i]->next = NULL;
    }
    for (int i = 0; i < graphSize; i++) {

        node* current = AdjacencyList[i];
        do {
            current = current->next;
            if (current == NULL)
                break;
            node* newNode = new node();
            newNode->data = AdjacencyList[i]->data;
            newNode->AdjacencyListVertexID = AdjacencyList[i]->AdjacencyListVertexID;
            newNode->next = tranposedAdjacencyList[current->AdjacencyListVertexID]->next;
            tranposedAdjacencyList[current->AdjacencyListVertexID]->next = newNode;
        } while (current->next != NULL);

    }
    representedAsTransposedAdjacencyList = true;
}
void graph::displayAdjacencyList() {          //a visualized way to see the AdjacencyList
    if (!representedAsAdjacencyList) {
        cout << "GRAPH IS NOT REPRESENTED AS Adjacency LIST YET!\n YOU NEED TO USE: representAsAdjacencyList() OR  representAsAdjacencyListNoSelfLoops() FIRST\n";
        return;
    }
    cout << "ADJACENCY LIST:\n";

    for (int i = 0; i < graphSize; i++) {
        node* current = AdjacencyList[i];
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }

    cout << "_____________________________________\n";
}
void graph::displayTransposedAdjacencyList() {          //a visualized way to see the transposed AdjacencyList
    if (!representedAsTransposedAdjacencyList) {
        cout << "GRAPH IS NOT REPRESENTED AS TRANSPOSED Adjacency LIST YET!\n YOU NEED TO USE: transposeAdjacencyList() FIRST\n";
        return;
    }
    cout << "TRANSPOSED Adjacency LIST:\n";
    for (int i = 0; i < graphSize; i++) {
        node* current = tranposedAdjacencyList[i];     //created a node to iterate through the whole AdjacencyList and print its values
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
    cout << "_____________________________________\n";
}

//AdjacencyArray methods

void graph::representAsAdjacencyArray() {          //setting connections to the graph randomly in the AdjacencyArray
    if (dataSetInput) {
        cout << "Only Linked List Operations Possible When the Input Is A DataSet!\n";
        return;
    }



    bool randomTrueOrFalse = false;
    int adjacencyEdgesArrayFillCounter = 0;
    for (int i = 0; i < graphSize; i++) {

        for (int j = 0; j < graphSize; j++) {
            randomTrueOrFalse = 0 + (rand() % (1 - 0 + 1));
            if (randomTrueOrFalse) {
                if (AdjacencyVerticesArray[i] == -1)
                    AdjacencyVerticesArray[i] = adjacencyEdgesArrayFillCounter;
                AdjacencyEdgesArray[adjacencyEdgesArrayFillCounter] = Vertices[j];
                adjacencyEdgesArrayFillCounter++;
            }
        }
    }
    AdjacencyVerticesArray[graphSize] = adjacencyEdgesArrayFillCounter;
    representedAsAdjacencyArray = true;
}
void graph::displayAdjacencyArray() {            //a visualized way to see the AdjacencyArray
    if (dataSetInput) {
        cout << "Only Linked List Operations Possible When the Input Is A DataSet!\n";
        return;
    }


    if (!representedAsAdjacencyArray) {
        cout << "GRAPH IS NOT REPRESENTED AS Adjacency Array YET!\n YOU NEED TO USE: representAsAdjacencyArray() FIRST\n";
        return;
    }

    cout << "Adjacency Vertex Array:\n";
    for (int i = 0; i <= graphSize; i++) {

        cout << AdjacencyVerticesArray[i] << ",";
    }
    cout << endl;
    cout << "\nAdjacency Edges Array:\n";
    for (int i = 0; i < graphSize * graphSize; i++) {

        if (AdjacencyEdgesArray[i] != 0)
            cout << AdjacencyEdgesArray[i] << ",";
    }
    cout << endl;
}


bool graph::isStronglyConnected_ListDfs(verteses_state& vs) {   //testing if a graph is strongly connected using dfs on linked list
    if (!representedAsAdjacencyList) {
        cout << "GRAPH IS NOT REPRESENTED AS Adjacency LIST YET!\n YOU NEED TO USE: representAsAdjacencyList() OR  representAsAdjacencyListNoSelfLoops() FIRST\n";
        return false;
    }
    if (!representedAsTransposedAdjacencyList) {
        cout << "GRAPH IS NOT REPRESENTED AS TRANSPOSED Adjacency LIST YET!\n YOU NEED TO USE: transposeAdjacencyList() FIRST\n";
        return false;
    }

    int counter = 0;         //number of verteses reached


    vs.init(*this);         //initializing verteses states and dfs_num and finish_num

    DFS_List(1, *this, vs); //preforming dfs on vertex 1

    for (int i = 0; i < graphSize; i++) {
        if (*vs.state[i] == "finished")
            counter++;      //adding 1 to the counter for every vertex we find it finished (reachable)
    }


    vs.init(*this);         //initializing verteses states and dfs_num and finish_num before preforming dfs on the transposed graph
    DFS_TransposedList(1, *this, vs); //preforming dfs on vertex 1 in the transposed graph

    for (int i = 0; i < graphSize; i++) {
        if (*vs.state[i] == "finished")
            counter++;      //adding 1 to the counter for every vertex we find it finished (reachable)
    }

    vs.init(*this);         //initializing verteses states and dfs_num and finish_num before ending the function
                            //(we might want to use them later in the program so they need to be initialized)

    if (counter == graphSize * 2) 
        return true;         //returning true ifcounter if its equal to graphSize * 2 
                             //(all verteses reachable from vertex 1 in both graphs normal graph and its transpose)
    else return false;
}

bool graph::isStronglyConnected_MatDfs(verteses_state& vs) {    //same as the previous one but this function uses DFS on Matrix
    if (dataSetInput) {
        cout << "Only Linked List Operations Possible When the Input Is A DataSet!\n";
        return 0;
    }


    if (!representedAsAdjacencyMatrix) {
        cout << "GRAPH IS NOT REPRESENTED AS Adjacency MATRIX YET!\n YOU NEED TO USE: representAsAdjacencyMatrix() FIRST\n";
        return false;
    }

    int counter = 0;


    vs.init(*this);
    DFS_Mat(1, *this, vs);

    for (int i = 0; i < graphSize; i++) {
        if (*vs.state[i] == "finished")
            counter++;
    }

    this->transopseAdjacencyMatrix();

    vs.init(*this);
    DFS_Mat(1, *this, vs);

    for (int i = 0; i < graphSize; i++) {
        if (*vs.state[i] == "finished")
            counter++;
    }

    vs.init(*this);
    this->transopseAdjacencyMatrix();
    if (counter == graphSize * 2)
        return true;
    else return false;
}

void graph::displayComp() {       //displays the component for each vertex in cheryan-mhelhorn-gabow
    for (int i = 0; i < graphSize; i++) {
        cout << i + 1 << ": " << comp[i] << endl;
    }
    cout << "________________________________________________\n";
}

void graph::addnodeToList(node* head, node* newNode) {   //function for adding a node to a linked list
    newNode->headParent = head;
    newNode->next = head->next;
    head->next = newNode;
}

//function for representing the graph as a linked list using DataSet text input that has the form:
//   EXAMPLE:
// 
// 5 6    node 5 have a connection with node 6
// 6 5    node 6 have a connection with node 5
// 4 7    node 4 have a connection with node 7
// 1 2    node 1 have a connection with node 2
void graph::representAsAdjacencyListUsingDataSet(string filepath){
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "Error Opening File!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int num1, num2;
        if (!(ss >> num1 >> num2)) {
            cerr << "Invalid Input Format!" << endl;
            continue;
        }

        node* newNode1 = new node();
        newNode1->data = ++num2;
        newNode1->AdjacencyListVertexID = num2;
        newNode1->next = NULL;

        if (AdjacencyList[num1] == NULL) {
            AdjacencyList[num1] = newNode1;
        }
        else {
            addnodeToList(AdjacencyList[num1], newNode1);
        }
    }

    file.close();
    representedAsAdjacencyList = true;
}

//______________________________________________________________________________

verteses_state::verteses_state(int graphSize) : dfs_counter(1), finish_counter(1) {
    for (int i = 0; i < 1005; i++) {  // Initialize vertices as undiscovered
        state[i] = new string("new");
        finish_num[i] = new int(-1);
        dfs_num[i] = new int(-1);
    }
    this->graphSize = graphSize;
}

void verteses_state::init(graph& g) {    //initializer function for verteses states and dfs_num and finish_num and the stacks
    for (int i = 0; i < g.graphSize; i++) {
        *state[i] = "new";
        *finish_num[i] = -1;
        *dfs_num[i] = -1;
    }
    dfs_counter = 1;
    finish_counter = 1;

    g.oStack->top = -1;
    g.rStack->top = -1;

}

void verteses_state::display_versteses_states() {      //prints the states of each vertex
    for (int i = 0; i < graphSize; i++)
        cout << "Vertex " << i + 1 << " : " << *state[i] << endl;
    cout << "________________________________________________________________________________________________\n";
}

void verteses_state::display_versteses_dfsnum() {     //prints the DFS number of each vertex
    for (int i = 0; i < graphSize; i++)
        cout << "Vertex " << i + 1 << " dnum is : " << *dfs_num[i] << endl;
    cout << "________________________________________________________________________________________________\n";
}

void verteses_state::display_versteses_fnum() {       //prints the Finish number of each vertex
    for (int i = 0; i < graphSize; i++)
        cout << "Vertex " << i + 1 << " fnum is : " << *finish_num[i] << endl;
    cout << "________________________________________________________________________________________________\n";
}

//__________________________________________________

void DFS_Mat(int vertex, graph& g, verteses_state& vs) {   
    if (g.dataSetInput) {
        cout << "Only Linked List Operations Possible When the Input Is A DataSet!\n";        return;
    }
    if (vertex < 1 || vertex > g.graphSize) return;   //check if vertex exsist

    vertex--;     // Convert to 0-based index

    vs.state[vertex] = new string("active");      //mark vertex as active

    vs.dfs_num[vertex] = new int(vs.dfs_counter++);//assign a dfs number for the vertex

    for (int i = 0; i < g.graphSize; i++) { //iterate trough vertex edges
        if (g.AdjacencyMatrix[vertex][i] == 1 && *vs.state[i] == "new") 
            DFS_Mat(i + 1, g, vs);   //run DFS on vertex if its not descoverd
    }   
    vs.finish_num[vertex] = new int(vs.finish_counter++); //assign a Finish number for the vertex

    vs.state[vertex] = new string("finished");   //mark vertex as finished
}

void DFS_Undirected(int vertex, graph& g, verteses_state& vs, int TE[][2], int& TE_count, int BE[][2], int& BE_count) {
    if (vertex < 1 || vertex > g.graphSize) return;    //check if vertex exsist

    vertex--; // Convert to 0-based index
    *vs.state[vertex] = "active";
    *vs.dfs_num[vertex] = vs.dfs_counter++;

    for (int i = 0; i < g.graphSize; i++) {   //iterate trough vertex edges

        if (g.AdjacencyMatrix[vertex][i] == 1) { // Edge exists
            if (*vs.state[i] == "new") {
                // Tree Edge
                TE[TE_count][0] = vertex + 1; // Store as 1-based index
                TE[TE_count][1] = i + 1;
                TE_count++;
                DFS_Undirected(i + 1, g, vs, TE, TE_count, BE, BE_count);
            }
            else if (*vs.state[i] == "active" && i != vertex) {
                // Back Edge (avoid self-loops)
                BE[BE_count][0] = vertex + 1; // Store as 1-based index
                BE[BE_count][1] = i + 1;
                BE_count++;
            }
        }
    }

    *vs.finish_num[vertex] = vs.finish_counter++; // Increment after assignment
    *vs.state[vertex] = "finished";
}
void DFS_List(int vertex, graph& g, verteses_state& vs) {
    if (!g.representedAsAdjacencyList) {
        cout << "GRAPH IS NOT REPRESENTED AS Adjacency LIST YET!\n YOU NEED TO USE: representAsAdjacencyList() OR  representAsAdjacencyListNoSelfLoops() FIRST\n";
        return;
    }


    if (vertex < 1 || vertex > g.graphSize) return;   //check if vertex exsist

    vertex--;       // Convert to 0-based index

    vs.state[vertex] = new string("active");  //mark vertex as active

    vs.dfs_num[vertex] = new int(vs.dfs_counter++);


    node* current = g.AdjacencyList[vertex];
    while (current != NULL) {                //iterate trough vertex edges
        if (*vs.state[current->data - 1] == "new") {
            DFS_List(current->data, g, vs); //run DFS on vertex if its not descoverd
        }
        current = current->next;
    }

    vs.finish_num[vertex] = new int(vs.finish_counter++);  //assign a Finish number for the vertex

    vs.state[vertex] = new string("finished");  //mark vertex as finished

}
void DFS_TransposedList(int vertex, graph& g, verteses_state& vs) {  //same as the previous function but on transposed graph
    if (vertex < 1 || vertex > g.graphSize) return;

    vertex--;
    *vs.state[vertex] = "active";
    *vs.dfs_num[vertex] = vs.dfs_counter++;

    node* current = g.tranposedAdjacencyList[vertex];
    while (current != NULL) {
        if (*vs.state[current->data - 1] == "new") {
            DFS_List(current->data, g, vs);
        }
        current = current->next;
    }

    *vs.finish_num[vertex] = vs.finish_counter++;
    *vs.state[vertex] = "finished";
}

void DepthFirstSearch(graph g, verteses_state& v) {
    if (g.representedAsAdjacencyList) {
        for (int i = 0; i < 10; i++) {
            if (*v.state[i] == "new")
                DFS_List(i + 1, g, v);
        }
        cout << "\nDepth First Search Performed Using DFS_LIST is done!\n";
    }
    else if (g.representedAsAdjacencyMatrix) {
        if (g.dataSetInput) {
            cout << "Only Linked List Operations Possible When the Input Is A DataSet!\n";
            return;
        }


        for (int i = 0; i < 10; i++) {
            if (*v.state[i] == "new")
                DFS_Mat(i + 1, g, v);
        }
        cout << "\nDepth First Search Performed Using DFS_Mat is done!\n";
    }
    else {
        cout << "\nCannot Perform Depth First Search As The Given Graph Is Not Represented As List Or Matrix Yet!\n";
    }
}

void DFS_Cheriyan_Mehlhorn_Gabow_List(int vertex, graph& g, verteses_state& vs) {
    if (vertex < 1 || vertex > g.graphSize) return;

    vertex--;

    *vs.state[vertex] = "active";
    *vs.dfs_num[vertex] = vs.dfs_counter++;

    g.oStack->push(vertex + 1);
    g.rStack->push(vertex + 1);

    node* current = g.AdjacencyList[vertex]->next;
    while (current != NULL) {
        if (*vs.state[current->data - 1] == "new") {
            DFS_Cheriyan_Mehlhorn_Gabow_List(current->data, g, vs);
        }
        else {
            if (g.oStack->exsist(current->data - 1))
                while (vs.dfs_num[current->data - 1] < vs.dfs_num[g.rStack->getTop() - 1]) {
                    g.rStack->pop();
                }
        }
        current = current->next;
    }

    *vs.finish_num[vertex] = vs.finish_counter++;
    *vs.state[vertex] = "finished";


    if (vertex + 1 == g.rStack->getTop()) {
        g.rStack->pop();
        int w = 0;
        do {
            w = g.oStack->pop() - 1;
            g.comp[w] = vertex + 1;
        } while (w + 1 != vertex + 1);
    }

}

void Cheriyan_Mehlhorn_Gabow(graph g, verteses_state& v) {

    v.init(g);
    for (int i = 0; i < g.graphSize; i++) {

        if (*v.state[i] == "new")
            DFS_Cheriyan_Mehlhorn_Gabow_List(i + 1, g, v);
    }
}

void graph::DFS_JensSchmidt(int vertex, graph& g, verteses_state& vs, int parent[], int& dfs_counter, int low[], int bridges[][2], int& bridge_count, int cut_vertices[], int& cut_vertex_count) {
    if (vertex < 1 || vertex > g.graphSize) return;

    vertex--;    // Convert to 0-based index

    *vs.state[vertex] = "active";
    *vs.dfs_num[vertex] = dfs_counter;
    low[vertex] = dfs_counter;
    dfs_counter++;

    int children = 0;      // Number of children in DFS tree

    for (int i = 0; i < g.graphSize; i++) {
        if (g.AdjacencyMatrix[vertex][i] == 1) {         // Edge exists
            if (*vs.state[i] == "new") {         // Tree edge
                parent[i] = vertex;
                children++;
                DFS_JensSchmidt(i + 1, g, vs, parent, dfs_counter, low, bridges, bridge_count, cut_vertices, cut_vertex_count);

                // Update low number of vertex
                low[vertex] = min(low[vertex], low[i]);

                // Check for bridge
                if (low[i] > *vs.dfs_num[vertex]) {
                    bridges[bridge_count][0] = vertex + 1; // Store bridge (1-based index)
                    bridges[bridge_count][1] = i + 1;
                    bridge_count++;
                }

                // Check for cut vertex
                if (parent[vertex] == -1 && children > 1) {
                    cut_vertices[cut_vertex_count] = vertex + 1; // Root with multiple children
                    cut_vertex_count++;
                }
                if (parent[vertex] != -1 && low[i] >= *vs.dfs_num[vertex]) {
                    cut_vertices[cut_vertex_count] = vertex + 1; // Non-root with a child having low[i] >= dfs_num[vertex]
                    cut_vertex_count++;
                }
            }
            else if (i != parent[vertex]) { // Back edge
                low[vertex] = min(low[vertex], *vs.dfs_num[i]);
            }
        }
    }

    *vs.finish_num[vertex] = dfs_counter;
    *vs.state[vertex] = "finished";
}
