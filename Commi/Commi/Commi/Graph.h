#pragma once
#include <glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

int n;
int** helpinter;
int* result;
int*** inter;
const int maxSize = 20;
int amountVerts;

class Graph
{
	vector<int> vertList;
	bool* visitedVerts = new bool[vertList.size()];
public:
	int adjMatrix[maxSize][maxSize] = { 0 };
	Graph();
	~Graph();
	void DrawGraph();
	void InsertNode(const int& vertex1, const int& vertex2, int weight);
	void InsertVertex(const int& vertex);
	void DeleteVertex();
	int GetVertPos(const int& vertex);
	bool Empty();
	bool Full();
	void Print();
};

int R;

struct vertCoord
{
	int x, y;
};
vertCoord vertC[20];

void Graph::InsertVertex(const int& vertex)
{
	if (!this->Full())
	{
		this->vertList.push_back(vertex);
	}
	else
	{
		cout << "Graph is full. " << endl;
		return;
	}
}

void Graph::DeleteVertex()
{
	this->vertList.pop_back();
}

bool Graph::Empty()
{
	if (this->vertList.size() != 0)
		return false;
	else
		return true;
}

bool Graph::Full()
{
	return (vertList.size() == maxSize);
}


int Graph::GetVertPos(const int& vertex)
{
	for (int i = 0; i < this->vertList.size(); ++i) 
	{
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}

Graph::Graph()
{
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

Graph::~Graph() {}

Graph makeGraph()
{
	Graph graph;
	int amountNodes, sourceVertex, targetVertex, edgeWeight;
	cout << "Amount of nodes: "; cin >> amountVerts; cout << endl;
	cout << "Amount of ribbons: "; cin >> amountNodes; cout << endl;
	for (int i = 1; i <= amountVerts; ++i)
	{
		int* vertPtr = &i;
		graph.InsertVertex(*vertPtr);
	}

	for (int i = 0; i < amountNodes; ++i) 
	{
		cout << "Start node: "; cin >> sourceVertex; cout << endl;
		int* sourceVertPtr = &sourceVertex;
		cout << "End node: "; cin >> targetVertex; cout << endl;
		int* targetVertPtr = &targetVertex;

		cout << "Ribbon's weight: "; cin >> edgeWeight; cout << endl;
		graph.InsertNode(*sourceVertPtr, *targetVertPtr, edgeWeight);
	}
	cout << endl;
	return graph;
}

void Graph::InsertNode(const int& vertex1, const int& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0
			&& this->adjMatrix[vertPos2][vertPos1] != 0)
		{
			cout << "Road exists" << endl;
			return;
		}
		else
		{
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
	else
	{
		cout << "Cannot insert node" << endl;
		return;
	}
}

void Graph::Print()
{
	if (!this->Empty()) 
	{
		cout << "The matrix: " << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j)
			{
				cout << " " << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
}

Graph graph;

void Vig(int*** inter, int n, int** helpinter, int* path)
{
	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i < n; i++)
		{
			int min = 1000000;
			for (int j = 0; j < n; j++)
				if (inter[i][j] && min > *inter[i][j])
					min = *inter[i][j];
			for (int j = 0; j < n; j++)
				if (inter[i][j])
					*inter[i][j] -= min;
		}
		for (int j = 0; j < n; j++)
		{
			int min = 1000000;
			for (int i = 0; i < n; i++)
				if (inter[i][j] && min > *inter[i][j])
					min = *inter[i][j];
			for (int i = 0; i < n; i++)
				if (inter[i][j])
					*inter[i][j] -= min;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				helpinter[i][j] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (inter[i][j] && !*inter[i][j])
				{
					int hmin = 1000000;
					int vmin = 1000000;
					for (int l = 0; l < n; l++)
						if (l != i && inter[l][j] && hmin > *inter[l][j])
							hmin = *inter[l][j];

					for (int l = 0; l < n; l++)
						if (l != j && inter[i][l] && vmin > *inter[i][l])
							vmin = *inter[i][l];

					helpinter[i][j] = hmin + vmin;
				}
			}
		int mcost = 0, mi = 0, mj = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (inter[i][j] && mcost < helpinter[i][j])
				{
					mcost = helpinter[i][j];
					mi = i;
					mj = j;
				}
		path[mi] = mj;

		for (int i = 0; i < n; i++)
			inter[i][mj] = nullptr;
		for (int i = 0; i < n; i++)
			inter[mi][i] = nullptr;
		inter[mj][mi] = nullptr;
	}
}

void Prepare(int***& inter, int& n, int**& helpinter, int*& result)
{
	n = amountVerts;
	helpinter = new int* [n];
	result = new int[n];
	inter = new int** [n];
	for (int i = 0; i <= n; i++)
	{
		helpinter[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		inter[i] = new int* [n];
		for (int j = 0; j < n; j++)
		{
			if (graph.adjMatrix[i][j] == 0)
			{
				inter[i][j] = nullptr;
				continue;
			}
			inter[i][j] = new int(graph.adjMatrix[i][j]);
		}
	}
}

void MinPath(int*** inter, int n, int** helpinter, int* result)
{
	Prepare(inter, n, helpinter, result);
	int s = 0;
	Vig(inter, n, helpinter, result);
	for (int i = 0, j = 0; i < n; i++)
	{
		j = result[i];
		s += graph.adjMatrix[i][j];
	}
	cout << "Minimal way: ";
	int temp = 0;
	for (int l = 0; l < n;)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (temp == 0 || i + 1 == temp)
			{
				if (temp == 0) cout << i + 1;
				j = result[i];
				temp = j + 1;
				if (temp > 0)	cout << " -> " << temp;
				l++;
			}
		}
	}
	cout << " = " << s;
	cout << endl;
}

void setCoord(int i, int n)
{
	int R_;
	int x0 = 1200 / 2;
	int y0 = 800 / 2;
	R = 5 * (800 / 13) / n;
	R_ = 800 / 2 - R - 10;
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0;
	float x1 = R_ * sin(theta) + x0;
	vertC[i].x = x1;
	vertC[i].y = y1;
}

void CircNodeText(int nom, int x1, int y1)
{
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[j]);
}

void drawCircle(int x, int y, int R)
{
	glColor3f(139, 0, 255);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawVertex(int n)
{
	for (int i = 0; i < n; i++)
	{
		drawCircle(vertC[i].x, vertC[i].y, R);
		CircNodeText(i + 1, vertC[i].x, vertC[i].y);
	}
}

void drawLine(int text, int x0, int y0, int x1, int y1)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	CircNodeText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
}

void Graph::DrawGraph()
{
	int n = vertList.size();
	for (int i = 0; i < n; i++)
	{
		setCoord(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = adjMatrix[i][j];
			if (a != 0)
			{
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	drawVertex(n);
}

void MenuText(string text, int x1, int y1)
{
	string s = text;
	glRasterPos2i(x1 + 5, y1 - 20);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[j]);
}

void drawMenu()
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(150, 0);
	glVertex2i(150, 150);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, 30);
	glVertex2i(150, 30);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, 60);
	glVertex2i(150, 60);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, 90);
	glVertex2i(150, 90);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, 120);
	glVertex2i(150, 120);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, 150);
	glVertex2i(150, 150);
	glEnd();
	glColor3d(0, 0, 0);
	MenuText("Add node", 0, 150);
	glColor3d(0, 0, 0);
	MenuText("Delete node", 0, 120);
	glColor3d(0, 0, 0);
	MenuText("Type matrix", 0, 90);
	glColor3d(0, 0, 0);
	MenuText("New matrix", 0, 60);
	glColor3d(0, 0, 0);
	MenuText("Answer", 0, 30);
}

void mouseClick(int btn, int stat, int x, int y)
{
	if (stat == GLUT_DOWN)
	{
		if (x > 0 && x < 150 && y > 650 && y < 680)
		{
			int sourceVertex;
			int targetVertex;
			int edgeWeight;


			cout << "Start node: "; cin >> sourceVertex; cout << endl;
			int* sourceVertPtr = &sourceVertex;
			cout << "End node: "; cin >> targetVertex; cout << endl;
			int* targetVertPtr = &targetVertex;

			if (sourceVertex > amountVerts || targetVertex > amountVerts)
			{
				amountVerts++;
				int* vertPtr = &amountVerts;
				graph.InsertVertex(*vertPtr);
			}

			cout << "Ribbon's weight: "; cin >> edgeWeight; cout << endl;
			graph.InsertNode(*sourceVertPtr, *targetVertPtr, edgeWeight);
		}
		if (x > 0 && x < 150 && y > 680 && y < 710)
		{
			int sourceVertex;

			cout << "Type node: "; cin >> sourceVertex; cout << endl;
			int* sourceVertPtr = &sourceVertex;
			if (sourceVertex == amountVerts)
			{
				amountVerts--;
				graph.DeleteVertex();
			}
			else cout << "Cannot delete node \n";
		}
		if (x > 0 && x < 150 && y >  710 && y < 740)
		{
			graph.Print();
		}
		if (x > 0 && x < 150 && y >  740 && y < 770)
		{
			graph = makeGraph();
		}
		if (x > 0 && x < 150 && y > 770 && y < 800)
		{
			MinPath(inter, n, helpinter, result);
		}
	}
	glutPostRedisplay();
}

void display()
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1200, 0, 800);
	glViewport(0, 0, 1200, 800);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	graph.DrawGraph();
	drawMenu();
	glutSwapBuffers();
}