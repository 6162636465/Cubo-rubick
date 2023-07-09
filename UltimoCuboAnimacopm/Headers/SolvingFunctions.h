#pragma once
#include "Header.h"

//Solving Functions
std::string CreateNeighbors(int i)
{
	switch (i)
	{
	case 0:
		return "R";
		break;
	case 1:
		return "L";
		break;
	case 2:
		return "U";
		break;
	case 3:
		return "D";
		break;
	case 4:
		return "F";
		break;
	case 5:
		return "B";
		break;
	case 6:
		return "R'";
		break;
	case 7:
		return "L'";
		break;
	case 8:
		return "U'";
		break;
	case 9:
		return "D'";
		break;
	case 10:
		return "F'";
		break;
	case 11:
		return "B'";
		break;
	case 12:
		return "R2";
		break;
	case 13:
		return "L2";
		break;
	case 14:
		return "U2";
		break;
	case 15:
		return "D2";
		break;
	case 16:
		return "F2";
		break;
	case 17:
		return "B2";
		break;
	}
}
std::string CreateNeighbors(int i, std::string buff)
{
	char c;
	if (buff.length() == 1)
		c = buff[0];
	else
	{
		char a = buff[buff.length() - 2];
		char b = buff[buff.length() - 1];
		if (b == '2' || b == '\'')
			c = a;
		else
			c = b;
	}
	if (c == 'R')
	{
		switch (i)
		{
		case 0:
			return "B2";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "F2";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "D2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "U2";
			break;
		}
	}
	if (c == 'L')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "B2";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "F2";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "D2";
			break;
		case 14:
			return "U2";
			break;
		}

		if (i == 0 && c != 'R')
			return "R";
		if (i == 1 && c != 'L')
			return "L";
		if (i == 2 && c != 'U')
			return "U";
		if (i == 3 && c != 'D')
			return "D";
		if (i == 4 && c != 'F')
			return "F";
		if (i == 5 && c != 'B')
			return "B";
		if (i == 6 && c != 'R')
			return "R'";
		if (i == 7 && c != 'L')
			return "L'";
		if (i == 8 && c != 'U')
			return "U'";
		if (i == 9 && c != 'D')
			return "D'";
		if (i == 10 && c != 'F')
			return "F'";
		if (i == 11 && c != 'B')
			return "B'";
		if (i == 12 && c != 'R')
			return "R2";
		if (i == 13 && c != 'L')
			return "L2";
		if (i == 14 && c != 'U')
			return "U2";
		if (i == 15 && c != 'D')
			return "D2";
		if (i == 16 && c != 'F')
			return "F2";
		if (i == 17 && c != 'B')
			return "B2";
	}
	if (c == 'U')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "B2";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "D2";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "F2";
			break;
		}
	}
	if (c == 'D')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "B2";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "F2";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "U2";
			break;
		}
	}
	if (c == 'F')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "B2";
			break;
		case 5:
			return "B";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "D2";
			break;
		case 11:
			return "B'";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "U2";
			break;
		}
	}
	if (c == 'B')
	{
		switch (i)
		{
		case 0:
			return "R";
			break;
		case 1:
			return "L";
			break;
		case 2:
			return "U";
			break;
		case 3:
			return "D";
			break;
		case 4:
			return "F";
			break;
		case 5:
			return "F2";
			break;
		case 6:
			return "R'";
			break;
		case 7:
			return "L'";
			break;
		case 8:
			return "U'";
			break;
		case 9:
			return "D'";
			break;
		case 10:
			return "F'";
			break;
		case 11:
			return "D2";
			break;
		case 12:
			return "R2";
			break;
		case 13:
			return "L2";
			break;
		case 14:
			return "U2";
			break;
		}
	}
}
std::string Pre_SolveCube(Cube cube1)
{
	int ICS = cube1.IsSolved();
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "cross is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		if (am > 3)
			return "";
		q.pop();
		ICS = cur.IsSolved();
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " cross is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveCross1(Cube cube1)
{
	int ICS = cube1.IsCrossSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "cross is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		if (am > 3)
			return "";
		q.pop();
		ICS = cur.IsCrossSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " cross is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveOneCrossPiece(Cube cube1)
{
	int ICS = cube1.IsOneBottomCrossPieceSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "three cross pieces is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		q.pop();
		ICS = cur.IsOneBottomCrossPieceSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " three cross pieces is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveTwoCrossPieces(Cube cube1)
{
	int ICS = cube1.AreTwoBottomCrossPiecesSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "three cross pieces is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		q.pop();
		ICS = cur.AreTwoBottomCrossPiecesSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " three cross pieces is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveThreeCrossPieces(Cube cube1)
{
	int ICS = cube1.AreThreeCrossPiecesSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "three cross pieces is solved\n";
		//CrossColor = ICS;
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		//if (am > 3)
		//	return "";
		q.pop();
		ICS = cur.AreThreeCrossPiecesSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " three cross pieces is solved\n";
			//std::cout << "moves: " << am << "\n";
			//CrossColor = ICS;
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveFourCrossPieces(Cube cube1)
{
	int ICS = cube1.IsCrossSolved(CrossColor);
	if (ICS)
	{
		//ColorPrint(ICS);
		//std::cout << "cross is solved\n";
		return "";
	}
	int am = 0;
	int n = 0;
	std::vector<std::string> ngbrs;
	std::queue<std::string> q;
	Cube cur;
	std::string buff;
	for (int i = 0; i < 18; i++)
	{
		ngbrs.push_back(CreateNeighbors(i));
		q.push(ngbrs[n]);
		n++;
	}
	while (!q.empty())
	{
		cur = cube1;
		buff = q.front();
		am = cur.SetScramble(buff);
		q.pop();
		ICS = cur.IsCrossSolved(CrossColor);
		if (ICS)
		{
			//std::cout << buff << "\n";
			//ColorPrint(ICS);
			//std::cout << " cross is solved\n";
			//std::cout << "moves: " << am << "\n";
			return buff;
		}
		for (int i = 0; i < 15; i++)
		{
			ngbrs.push_back(buff + CreateNeighbors(i, buff));
			q.push(ngbrs[n]);
			n++;
		}
	}
}
std::string Pre_SolveOnePair(Cube cube1, std::string* sexymovecases, std::string* rotcases, std::string* aufcases, std::string* f2lcases)
{
	if (cube1.IsOneBottomPairSolved(CrossColor))
		return "";
	Cube cur, cur2, cur3, cur4;
	for (int l = 0; l < 21; l++)
	{
		cur = cube1;
		cur.SetScramble(sexymovecases[l]);
		cur2 = cur;
		for (int j = 0; j < 4; j++)
		{
			cur2 = cur;
			cur2.SetScramble(rotcases[j]);
			cur3 = cur2;
			for (int i = 0; i < 4; i++)
			{
				cur3 = cur2;
				cur3.SetScramble(aufcases[i]);
				cur4 = cur3;
				for (int n = 0; n < 103; n++)
				{
					cur4 = cur3;
					cur4.SetScramble(f2lcases[n]);
					//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
					//cur.PrintCube();
					if (cur4.IsOneBottomPairSolved(CrossColor))
					{
						return sexymovecases[l] + rotcases[j] + aufcases[i] + f2lcases[n];
					}
				}
			}
		}
	}
	std::cout << "error f2l 1st pair\n";
	return "";
}
std::string Pre_SolveTwoPairs(Cube cube1, std::string* sexymovecases, std::string* rotcases, std::string* aufcases, std::string* f2lcases)
{
	if (cube1.AreTwoBottomPairsSolved(CrossColor))
		return "";
	Cube cur, cur2, cur3, cur4;
	for (int l = 0; l < 21; l++)
	{
		cur = cube1;
		cur.SetScramble(sexymovecases[l]);
		cur2 = cur;
		for (int j = 0; j < 4; j++)
		{
			cur2 = cur;
			cur2.SetScramble(rotcases[j]);
			cur3 = cur2;
			for (int i = 0; i < 4; i++)
			{
				cur3 = cur2;
				cur3.SetScramble(aufcases[i]);
				cur4 = cur3;
				for (int n = 0; n < 103; n++)
				{
					cur4 = cur3;
					cur4.SetScramble(f2lcases[n]);
					//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
					//cur.PrintCube();
					if (cur4.AreTwoBottomPairsSolved(CrossColor))
					{
						return sexymovecases[l] + rotcases[j] + aufcases[i] + f2lcases[n];
					}
				}
			}
		}
	}
	std::cout << "error f2l 2nd pair\n";
	return "";
}
std::string Pre_SolveThreePairs(Cube cube1, std::string* sexymovecases, std::string* rotcases, std::string* aufcases, std::string* f2lcases)
{
	if (cube1.AreThreeBottomPairsSolved(CrossColor))
		return "";
	Cube cur, cur2, cur3, cur4;
	for (int l = 0; l < 21; l++)
	{
		cur = cube1;
		cur.SetScramble(sexymovecases[l]);
		cur2 = cur;
		for (int j = 0; j < 4; j++)
		{
			cur2 = cur;
			cur2.SetScramble(rotcases[j]);
			cur3 = cur2;
			for (int i = 0; i < 4; i++)
			{
				cur3 = cur2;
				cur3.SetScramble(aufcases[i]);
				cur4 = cur3;
				for (int n = 0; n < 103; n++)
				{
					cur4 = cur3;
					cur4.SetScramble(f2lcases[n]);
					//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
					//cur.PrintCube();
					if (cur4.AreThreeBottomPairsSolved(CrossColor))
					{
						return sexymovecases[l] + rotcases[j] + aufcases[i] + f2lcases[n];
					}
				}
			}
		}
	}
	std::cout << "error f2l 3rd pair\n";
	return "";
}
std::string Pre_SolveFourPairs(Cube cube1, std::string* aufcases, std::string* f2lcases)
{
	if (cube1.AreFourBottomPairsSolved(CrossColor))
		return "";
	// 1 - BLD unsolved; 2 - BRD unsolved; 3 - FRD unsolved; 4 - FLD unsolved.
	std::string rot;
	Cube cur = cube1;
	Cube cur2, cur3;
	switch (cube1.AreThreeBottomPairsSolved(CrossColor))
	{
	case 1:
		cur.TurnY2();
		rot = "y2";
		break;
	case 2:
		cur.TurnY();
		rot = "y";
		break;
	case 3:
		rot = "";
		break;
	case 4:
		cur.TurnYprime();
		rot = "y'";
		break;
	}
	std::string rot2;
	for (int i = 0; i < 4; i++)
	{
		cur2 = cur;
		cur2.SetScramble(aufcases[i]);
		cur3 = cur2;
		for (int n = 0; n < 103; n++)
		{
			cur2 = cur3;
			cur2.SetScramble(f2lcases[n]);
			//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
			//cur.PrintCube();
			if (cur2.AreFourBottomPairsSolved(CrossColor))
			{
				return rot + aufcases[i] + f2lcases[n];
			}
		}
	}
	std::cout << "error f2l\n";
	return "";
}
std::string Pre_OLL(Cube cube1, std::string* aufcases, std::string* ollcases)
{
	if (cube1.IsLastLayerOriented())
		return "";
	Cube cur, cur2;
	for (int i = 0; i < 4; i++)
	{
		cur = cube1;
		cur.SetScramble(aufcases[i]);
		cur2 = cur;
		for (int n = 0; n < 57; n++)
		{
			cur = cur2;
			cur.SetScramble(ollcases[n]);
			//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
			//cur.PrintCube();
			if (cur.IsLastLayerOriented())
			{
				return aufcases[i] + ollcases[n];
			}
		}
	}
	std::cout << "error oll\n";
	return "";
}
std::string Pre_PLL(Cube cube1, std::string* aufcases, std::string* pllcases)
{
	if (cube1.IsLastLayerPermuted())
		return "";
	Cube cur, cur2, cur3;
	for (int i = 0; i < 4; i++)
	{
		cur = cube1;
		cur.SetScramble(aufcases[i]);
		cur2 = cur;
		for (int n = 0; n < 21; n++)
		{
			cur = cur2;
			cur.SetScramble(pllcases[n]);
			//std::cout << i << " " << n << " " << aufcases[i] << " " << f2lcases[n] << "\n";
			//cur.PrintCube();
			for (int j = 0; j < 19; j++)
			{

				if (cur.IsLastLayerPermuted())
				{
					return aufcases[i] + pllcases[n];
				}
			}
		}
	}
	std::cout << "error pll\n";
	return "";
}
std::string Pre_AUF(Cube cube1, std::string* aufcases)
{
	if (cube1.IsSolved())
		return "";
	Cube cur, cur2;
	for (int i = 0; i < 4; i++)
	{
		cur = cube1;
		cur.SetScramble(aufcases[i]);
		if (cur.IsSolved())
		{
			return aufcases[i];
		}
	}
	std::cout << "error auf\n";
	return "";
}
std::string* ReadAlgsFromFile(int a)
{
	std::string path;
	int size;
	switch (a)
	{
	case 1:
		path = "Algorithms/F2L.txt";
		size = 103;
		break;
	case 2:
		path = "Algorithms/OLL.txt";
		size = 57;
		break;
	case 3:
		path = "Algorithms/PLL.txt";
		size = 21;
		break;
	case 4:
		path = "Algorithms/Scrambles.txt";
		size = 10000;
		break;
	}
	std::string* line = new std::string[size];
	if (line == NULL)
		return NULL;
	int i = 0;
	std::ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, line[i]);
			//std::cout << line[i] << std::endl;
			i++;
		}
	}
	fin.close();
	return line;
}
std::string* ReadAlgsFromFile(int a, int len)
{
	std::string path;
	int size;
	switch (a)
	{
	case 1:
		path = "C:\GoogleDisk\repos\Classes and Methods\Classes and Methods\Algorithms\F2L.txt";
		size = 103;
		break;
	case 2:
		path = "C:\GoogleDisk\repos\Classes and Methods\Classes and Methods\Algorithms\OLL.txt";
		size = 57;
		break;
	case 3:
		path = "C:\GoogleDisk\repos\Classes and Methods\Classes and Methods\Algorithms\PLL.txt";
		size = 21;
		break;
	case 4:
		path = "Algorithms/Scrambles.txt";
		size = len;
		break;
	}
	std::string* line = new std::string[size];
	if (line == NULL)
		return NULL;
	int i = 0;
	std::ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, line[i]);
			//std::cout << line[i] << std::endl;
			i++;
		}
	}
	fin.close();
	return line;
}
