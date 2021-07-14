#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

enum class State
{
	kEmpty,
	kObstacle,
	kClosed,
	kPath,
	kStart,
	kFinish
};

string CellString(State cell)
{
	switch (cell)
	{
	case State::kObstacle:
		return "⛰️ ";
	case State::kPath:
		return "🚗 ";
	case State::kStart:
		return "🚦 ";
	case State::kFinish:
		return "🏁 ";
	default:
		return "0  ";
	}
}

vector<State> ParseLine(string line)
{
	istringstream stream_line(line);

	int n;
	char c;
	vector<State> parsed_line;

	while (stream_line >> n >> c)
	{
		parsed_line.push_back(n == 0 ? State::kEmpty : State::kObstacle);
	}

	return parsed_line;
}

void PrintBoard(vector<vector<State>> board)
{
	for (auto row : board)
	{
		for (auto element : row)
			cout << CellString(element) << " ";
		cout << "\n";
	}
}

vector<vector<State>> ReadBoardFile(string path)
{
	ifstream board_file(path);

	vector<vector<State>> board;
	if (board_file)
	{
		string line;
		while (getline(board_file, line))
			board.push_back(ParseLine(line));
	}

	return board;
}

bool Compare(vector<int> first, vector<int> second)
{
	// node = {x, y, g, h}

	// f = g + h
	if ((first[2] + first[3]) > (second[2] + second[3]))
		return true;

	return false;
}

int Heuristic(int x1, int y1, int x2, int y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}

bool CheckValidCell(int x, int y, vector<vector<State>> &board)
{
	if (y >= board[0].size() || y < 0)
		return false;
	if (x >= board.size() || x < 0)
		return false;

	return board[x][y] == State::kEmpty;
}

void AddToOpen(int x, int y, int g, int h,
			   vector<vector<int>> &openNodes,
			   vector<vector<State>> &board)
{
	vector<int> node = {x, y, g, h};
	openNodes.push_back(node);

	board[x][y] = State::kClosed;
}

void CellSort(vector<vector<int>> *v)
{
	sort(v->begin(), v->end(), Compare);
}

void ExpandNeighbors(vector<int> currentNode, int goal[2], vector<vector<int>> &openNodes, vector<vector<State>> &board)
{
	int x = currentNode[0];
	int y = currentNode[1];
	int g = currentNode[2];
	int h = currentNode[3];

	// directional deltas
	const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	// iterate over all directions
	for (auto i : delta)
	{
		int x2 = x + i[0];
		int y2 = y + i[1];
		if (CheckValidCell(x2, y2, board))
		{
			//call function to add to openNodes
			int h2 = Heuristic(x2, y2, goal[0], goal[1]);
			int g2 = g + 1;
			AddToOpen(x2, y2, g2, h2, openNodes, board);
		}
	}
}

vector<vector<State>> Search(vector<vector<State>> board, int start[2], int goal[2])
{
	vector<vector<int>> open;

	int g = 0;
	int h = Heuristic(start[0], start[1], goal[0], goal[1]);
	int x = start[0];
	int y = start[1];

	AddToOpen(x, y, g, h, open, board);

	while (!open.empty())
	{
		CellSort(&open);

		auto current = open.back();
		open.pop_back();

		x = current[0];
		y = current[1];
		board[x][y] = State::kPath;

		if (x == goal[0] && y == goal[1])
		{
			board[start[0]][start[1]] = State::kStart;
			board[goal[0]][goal[1]] = State::kFinish;
			return board;
		}

		ExpandNeighbors(current, goal, open, board);
	}

	cout << "No path found!\n";
	vector<vector<State>> empty;
	return empty;
}

#include "test.cpp"
int main()
{
	auto board = ReadBoardFile("1.board");
	int start[2] = {0, 0};
	int goal[2] = {4, 5};

	auto solution = Search(board, start, goal);
	PrintBoard(solution);

	TestHeuristic();
	TestAddToOpen();
	TestCompare();
	TestSearch();
	TestCheckValidCell();
	TestExpandNeighbors();
	return 0;
}
