#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x;
	int y;
};

bool checkRectangle(vector<Point> points)
{
	return abs(points[0].x - points[1].x) +
			   abs(points[0].y - points[1].y) ==
		   abs(points[2].x - points[3].x) +
			   abs(points[2].y - points[3].y);
};


Point oddOneOut(int n, vector<Point> &points)
{
	bool flag = false;
	vector<bool> validation(n);
	for (int i = 0; i < n - 3; ++i)
	{
		if (!validation[i])
		{
			for (int j = i + 1; j < n - 2; ++j)
			{
				if (!validation[j])
				{
					for (int k = i + 2; k < n - 1; ++k)
					{
						if (!validation[k])
						{
							for (int l = i + 3; l < n; ++l)
							{
								if (!validation[l])
								{
									if (checkRectangle({points[i], points[j], points[k], points[l]}))
									{
										validation[i] = validation[j] = validation[k] = validation[l] = true;
										flag = true;
										break;
									}
								}
							}
							if(flag) break;
						}
					}
					if(flag) break;
				}
			}
		}
	}

	for (int i; i < n; ++i)
	{
		if (validation[i] == false)
		{
			return points[i];
		}
	}
	return {0,0};
}

int main()
{
	int n;
	cin >> n;
	vector<Point> points;
	for (int i = 0; i < 4 * n + 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		Point p_temp = {a, b};
		points.push_back(p_temp);
	}
	Point p = oddOneOut(4 * n + 1, points);
	cout << p.x << " " << p.y;
	return 0;
}