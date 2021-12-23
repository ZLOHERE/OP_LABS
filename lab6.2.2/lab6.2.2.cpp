#include <iostream>
#include<deque>
using namespace std;
int sortmas_x(int**& arr,int size);
int main()
{
    int size;
	cin >> size;
    int** arr = new int*[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[2];
		int x, y;
		cin >> x>>y;
		arr[i][0] = x;
		arr[i][1] = y;
	}
	int lef_point = sortmas_x(arr, size);
	deque<int> number;
	deque<int> VO;
	number.push_front(lef_point);
	int left_points = 0;
	int left;
	for (int i = 0; i < size; i++)
	{
		for (int iter = 0; iter < size; iter++)
		{
			if ((i==iter)or(i==lef_point)or(iter==lef_point))
			{//(arr[i][0]-arr[0][0])*(arr[iter][1]-arr[iter][1])-(arr[iter][1]-arr[0][1])*(arr[iter][0]-arr[i][0]) b_x=arr[i][0] a_x=arr[0][0] c_y=arr[iter][1] b_y =arr[iter][1] c_x=arr[iter][0] a_y=arr[0][1] 
				continue;
			}			 //
			left = (arr[i][0] - arr[lef_point][0]) * (arr[iter][1] - arr[iter][1]) - (arr[iter][1] - arr[lef_point][1])* (arr[iter][0] - arr[i][0]);
			if (left>0)
			{
				left_points += 1;
			}
		}
		if ((left_points==(number.size()-1)and(i!=lef_point)))
		{
			number.push_front(i);
			if (number.size()!=size)
			{
				i = 0;
			}
			else
			{
				break;
			}
		}
		left_points = 0;
	}
	number.push_front(lef_point);
	int prev_num = number.back();
	VO.push_front(number.back());
	number.pop_back();
	int now_num = number.back();
	VO.push_front(number.back());
	number.pop_back();
	while (true)
	{
		double cosinus;
		int xa = arr[now_num][0] - arr[prev_num][0];
		int ya = arr[now_num][1] - arr[prev_num][1];
		double lastcos=-2;
		int n = 0;
		while (true)
		{
			if (number.back()==lef_point) {
				break;
			}
			int xb = arr[number.back()][0] - arr[now_num][0];
			int yb = arr[number.back()][1] - arr[now_num][1];
			cosinus = ((xa * xb) + (ya * yb)) / (sqrt(xa * xa + ya * ya) * sqrt(xb * xb + yb * yb));
			if ((sqrt(xa * xa + ya * ya) * sqrt(xb * xb + yb * yb))==0)
			{
				cosinus = 0;
			}
			if (lastcos<cosinus)
			{
				lastcos = cosinus;
				if (n>0)
				{
					VO.pop_front();
				}
				VO.push_front(number.back());
				number.pop_back();
				n += 1;
			}
			else
			{
				break;
			}
			
		}
		prev_num = now_num;
		now_num = VO.front();
		if (number.back()==lef_point)
		{
			break;
		}
	}
	while (!VO.empty())
	{
		cout << VO.back();
		VO.pop_back();
	}
	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
int sortmas_x(int**& arr, int size) {
	int minimum=arr[0][0];
	for (int i = 0; i < size-1; i++)
	{
		if (arr[i][0]<minimum)
		{
			minimum = i;
		}
	}
	return minimum;
}