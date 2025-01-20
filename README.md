# **Algorithms And DataStructer Task**

Syria-LattakiaUniversity-ComputerScience-ThirdYear-FirstSemester-2025. 
This repository contains Algorithms And Data Structures Task. 

حل وظيفة مقرر خورازميات وبنى المعطيات لجامعة اللاذقية كلية الهندسة المعلوماتية - سوريا

لقد قمنا ببناء برنامج متكامل وفعال لمعالجة متطلبات الوظيفة المطلوبة لمقرر الخوارزميات وبنى المعطيات

## Contents

- [**Algorithms And DataStructer Task**](#algorithms-and-datastructer-task)
  - [Contents](#contents)
  - [INFO](#info)
  - [Code Snippets](#code-snippets)
      - [Adjacencey Matrix](#adjacencey-matrix)
      - [Adjacencey List](#adjacencey-list)
      - [Adjacencey Array](#adjacencey-array)
    - [Depth First Search](#depth-first-search)
      - [DFS on Matrix](#dfs-on-matrix)
    - [DFS on List](#dfs-on-list)
      - [DFS On Undirected Graph](#dfs-on-undirected-graph)
      - [SCG on Matrix](#scg-on-matrix)
      - [SCG on List](#scg-on-list)
      - [Stack](#stack)
      - [Gabow DFS](#gabow-dfs)
      - [Gabow Function](#gabow-function)
      - [Display Comp](#display-comp)
      - [Jens Dfs](#jens-dfs)
  - [Executing\_The\_Program](#executing_the_program)
    - [ADJACENCEY ARRAY e](#adjacencey-array-e)
        - [output](#output)
    - [Strogly Connected Graph](#strogly-connected-graph)
        - [output](#output-1)
        - [output](#output-2)
    - [JENS SHMIDT](#jens-shmidt)
        - [output](#output-3)
  - [Sources](#sources)
    - [Books](#books)

## INFO

تم شرح اقسام الوظيفة كاملة في القسم الثاني من هذا الملف وتم تنفيذ بعض الخوارزميات مع توضيح الخرج الخاص بها في القسم الثالث وذلك لعدم اطالة هذا الملف
المشرف واسماء المشاركين في تصميم البرنامج

- #### Lattakia University - Syria [University Site](https://tishreen.edu.sy/en)
- **SuperVisor**
  - Dr. Raed Aljaberi
- **Students**
  - Mohammed Maher Nahhas 7178 (Group manager)
  - Mohammed Anas Yassen 6800
  - Mohammed Marwan Hasan 6760
  - Mohammed Nael Hasan 7258
  - Modar Ammar Othman 6884
  - Maher Alaa Alden Qrh Flah 7093
  - Abdullrahman Ali birqdar 6675
  - Abduallah Mohammed Ghandoor 6210

> ---

محمد ماهر نحاس 7178( مشرف المجموعة )
محمد انس ياسين 6800
محمد مروان حسن 6760
محمد نائل حسن 7258
مضر عمار عثمان 6884
ماهر علاء الدين قره فلاح 7093
عبدالرحمن علي بيرقدار 6675
عبدالله محمد غندور 6210

## Code Snippets

> ### Graph Represent

#### Adjacencey Matrix

هذا التابع يقوم بتوليد مصفوفة الجوار للبيان الموجه بشكل عشوائي

```cpp
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
```

هذا التابع يقوم بتوليد مصفوفة الجوار لبيان غير موجه وذلك باضافة شرط ان تكون المصفوفة متناظرة

```cpp
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
```

التابع هنا يعطينا منقول مصفوفة الجوار للبيان الموجه

```cpp
void graph::transopseAdjacencyMatrix() { //turning the Adjacency matrix into it's transpose
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
```

باستخدام هذا التابع يتم طباعة مصفوفة الجوار للبيان وذلك بعد اجراء بعض الاختبارات

```cpp
void graph::displayAdjacencyMatrix() { //a visualized way to see the vertices connections Matrix (AdjacencyMatrix)
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
cout << " ";
for (int i = 0; i < graphSize; i++) {
cout << Vertices[i] << " ";
}
cout << endl;
for (int i = 0; i < graphSize; i++) {
cout << Vertices[i] << ": ";
for (int j = 0; j < graphSize; j++) {
cout << AdjacencyMatrix[i][j] << " ";
}
cout << endl;
}
cout << "********\*\*********\_********\*\*********\n";

}
else {
cout << "TRANSPOSED Adjacency MATRIX:\n";
cout << " ";
for (int i = 0; i < graphSize; i++) {
cout << Vertices[i] << " ";
}
cout << endl;
for (int i = 0; i < graphSize; i++) {
cout << Vertices[i] << ": ";
for (int j = 0; j < graphSize; j++) {
cout << AdjacencyMatrix[i][j] << " ";
}
cout << endl;
}
cout << "********\*\*********\_********\*\*********\n";

}
}

```

#### Adjacencey List

هذا التابع يقوم بتمثيل البيان بشكل لائحة التجاور وذلك بتطبيق العمليات على اللوائح المترابطة بلغة c++

```cpp
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
```

نفس عمل التابع السابق لكن يقوم بتوليد البيان بدون وجود حلقة ذاتية على نفس العقدة

```cpp
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
```

ايجاد مقلوب البيان المنشأ باستخدام اللوائح المترابطةبالاضافة الى طريقة لطباعة البيان المنشأ بلائحة التجاور

```cpp
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
```

#### Adjacencey Array

توليد البيان باستخدام مصفوفة التجاور بالاضافة الى طريقة لطباعة هذه المصفوفة

```cpp
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
```

> ### DFS

### Depth First Search

خوارزميةالبحث بالعمق التي تبحث عن كل العقد التي هي غير مكتشفة لتطبق عليها الخوارزمية

```cpp
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
```

#### DFS on Matrix

تطبيق خوارزمية البحث بالعمق لمصفوفة التجاور

```cpp
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
```

### DFS on List

تطبيق خوارزمية البحث بالعمق على لائحة التجاور

```cpp
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
```

تطبيق الخوارزمية على مقلوب لائحة الترابط

```cpp
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
```

#### DFS On Undirected Graph

```cpp
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
```

> ### Strongly Connected Graph

#### SCG on Matrix

اختبار ان البيان مترابط بقوة حيث البيان ممثل بمصفوفة الجوار

```cpp
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
```

#### SCG on List

تطبيق الاختبار على لائحة الترابط

```cpp
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
```

> ### Cheriyan Mehlhorn Gabow

#### Stack

تطبيق المكدس داخل البرنامج

```cpp
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
```

#### Gabow DFS

خوارزمية البحث بالعمق معدلة لخوارزمية غابو

```cpp
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
```

#### Gabow Function

التابع الخاص بالخوارزمية

```cpp
void Cheriyan_Mehlhorn_Gabow(graph g, verteses_state& v) {

    v.init(g);
    for (int i = 0; i < g.graphSize; i++) {

        if (*v.state[i] == "new")
            DFS_Cheriyan_Mehlhorn_Gabow_List(i + 1, g, v);
    }
}
```

#### Display Comp

طريقة تقوم بطباعة المكونات المتصلة بقوة لخوارزمية غابو

```cpp
void graph::displayComp() {       //displays the component for each vertex in cheryan-mhelhorn-gabow
    for (int i = 0; i < graphSize; i++) {
        cout << i + 1 << ": " << comp[i] << endl;
    }
    cout << "________________________________________________\n";
}
```

> ### Jens Schmidt

#### Jens Dfs

خوارزمية البحث بالعمق معدلة لاجل هذه الخوارزمية حيث سيتم تخزين الجسور و العقد المفصيلة في مصفوفات ثنائية لتسهيل عرضها حيث تم تنفيذ الخوارزمية في البرنامج الرئيسي فسم بعض تنفيذات البرنامج

```cpp
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
```

## Executing_The_Program

تنفيذ اقسام الوظيفة من البرنامج الرئيسي

### ADJACENCEY ARRAY e

> #### ADJACENCEY ARRAY REPRESENTATION AND DISPLAYING

```cpp
int main(){
 graph* g = new graph(7);  //pick any number between 1 and 10

 verteses_state* v = new verteses_state(g->graphSize);

 g->displayVerteses();

 g->representAsAdjacencyArray();
 g->displayAdjacencyArray();

}
```

##### output

![output3](https://i.imgur.com/k3gmfAl.png)

### Strogly Connected Graph

> #### LINKED LIST TRANSPOSE, DFS, AND TESTING STRONG CONNECTIVITY

```cpp
int main(){
  graph* g = new graph(4);  //pick any number between 1 and 10

  verteses_state* v = new verteses_state(g->graphSize);

  g->displayVerteses();

  g->representAsAdjacencyListNoSelfLoops(); //or g->representAsAdjacencyList();
  g->displayAdjacencyList();

  DFS_List(1, *g, *v); //choose any number between 1 and 10

  v->display_versteses_states();
  v->display_versteses_dfsnum();
  v->display_versteses_fnum();
  v->init(*g);

  g->transposeAdjacencyList();
  if (g->isStronglyConnected_ListDfs(*v))
      cout << "Graph IS Strongly Connected\n";
  else
      cout << "Graph IS Not Strongly Connected\n";

  cout << "----------------------------------------------------\n";


  g->displayTransposedAdjacencyList();
}
```

##### output

![output1](https://i.imgur.com/dKk4J02.png)

> #### MATRIX TRANSPOSE, DFS, AND TESTING STRONG CONNECTIVITY

```cpp
int main(){
 graph* g = new graph(6);  //pick any number between 1 and 10

 verteses_state* v = new verteses_state(g->graphSize);

 g->displayVerteses();

 g->representAsAdjacencyMatrix();
 g->displayAdjacencyMatrix();

 DFS_Mat(1, *g, *v); //choose any number between 1 and 10

 v->display_versteses_states();
 v->display_versteses_dfsnum();
 v->display_versteses_fnum();
 v->init(*g);

 if (g->isStronglyConnected_MatDfs(*v))
     cout << "Graph IS Strongly Connected\n";
 else
     cout << "Graph IS Not Strongly Connected\n";

 cout << "----------------------------------------------------\n";

 g->transopseAdjacencyMatrix();
 g->displayAdjacencyMatrix();
 }
```

##### output

![output2](https://i.imgur.com/gF5bb53.png)

### JENS SHMIDT

```cpp
int main(){
    graph* g = new graph(4);  //pick any number between 1 and 10

    verteses_state* v = new verteses_state(g->graphSize);



//Represent the graph as an undirected adjacency matrix
    g->representAsAdjacencyMatrixUnDir();
    g->displayAdjacencyMatrix();

    // Arrays to store parent, low numbers, bridges, and cut vertices
    int parent[10] = { -1 }; // Parent of each vertex in DFS tree
    int low[10] = { 0 };     // Low numbers for each vertex
    int bridges[100][2];     // Store bridges (edges) - assuming max 100 bridges
    int bridge_count = 0;    // Counter for bridges
    int cut_vertices[10];    // Store cut vertices - assuming max 10 cut vertices
    int cut_vertex_count = 0; // Counter for cut vertices

    // Perform DFS and classify edges
    int dfs_counter = 0;
    g->DFS_JensSchmidt(1, *g, *v, parent, dfs_counter, low, bridges, bridge_count, cut_vertices, cut_vertex_count);

    // Display results
    cout << "Bridges:\n";
    for (int i = 0; i < bridge_count; i++) {
        cout << "(" << bridges[i][0] << ", " << bridges[i][1] << ") ";
    }
    cout << "\nCut Vertices:\n";
    for (int i = 0; i < cut_vertex_count; i++) {
        cout << cut_vertices[i] << " ";
    }
    cout << endl;

}
```

##### output

![output4](https://i.imgur.com/Wqmb3YE.png)

## Sources

المراجع المستخدمة

### Books

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). _Introduction to Algorithms_ (4th ed.). MIT Press. [Link](https://mitpress.mit.edu/books/introduction-algorithms-fourth-edition)
2. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). _Introduction to Algorithms_ (3rd ed.). MIT Press. [Link](https://mitpress.mit.edu/books/introduction-algorithms-third-edition)
3. Mehlhorn, K., & Sanders, P. (2008). _Algorithms and Data Structures: The Basic Toolbox_. Springer. [Link](https://www.springer.com/gp/book/9783540779773)
4. Kleinberg, J. M., & Tardos, É. (2006). _Algorithm Design_. Addison-Wesley. [Link](https://www.pearson.com/us/higher-education/program/Kleinberg-Algorithm-Design/PGM319216.html)

