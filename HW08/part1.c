#include <stdio.h>
#define COL_COUNT 100

typedef struct 
{
	int x,
		y;
}Point_t;

typedef struct 
{
	Point_t left_up,
			right_down;
	double sum;

}Rectangle_t;

Point_t construct_point(int x, int y);
Rectangle_t construct_rectangle(Point_t left_up, Point_t right_down);
void print_rectangle(const Rectangle_t *rectangle);
void getSum(double table[][COL_COUNT], Rectangle_t *rectangle);
Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, Point_t left_up);
Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow);

int main(void)
{
	/* code */
	return 0;
}


Point_t construct_point(int x, int y)
{



}

Rectangle_t construct_rectangle(Point_t left_up, Point_t right_down)
{



}

void print_rectangle(const Rectangle_t *rectangle)
{



}

void getSum(double table[][COL_COUNT], Rectangle_t *rectangle)
{
	int row, col;
	double sum=0;

	for(row=Rectangle_t.Point_t.left_up.y; row<=Rectangle_t.Point_t.right_down.y; ++row)
		for(col=Rectangle_t.Point_t.left_up.x; col<=Rectangle_t.Point_t.right_down.x; ++col)
			sum+=table[row][col];

}

Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, Point_t left_up)
{
	int rDX;	/*x coordinate of the right down corner of the rec*/
	int rDY;	/*y coordinate of the right down corner of the rec*/
	double temp;
	/*initialize the rectangular with the one including only one point*/
	double sum=table[leftUpX][leftUpY];
	*rightDownY=left_up.y;
	*rightDownX=left_up.x;

	/*Try all feasible rectangulars by changing the right down corner*/
	for(rDY=leftUpY; rDY<nRow; ++rDY){
		for(rDX=leftUpX; rDX<COL_COUNT; ++rDX){
			temp=getSum(table, leftUpY, leftUpX, rDY, rDX);
			if(temp>sum){
				/*a better rectangular is found, perform an update */
				sum=temp;
				*rightDownY=rDY;
				*rightDownX=rDX;
			}
		}
	}
}

Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow)
{
	double temp;
	int lUY, lUX;	/*coordinates of the left upper corner*/
	int rDY, rDX;	/*coordinates of the right down corner*/
	/*initialize the rectangular with the one including only origin point*/
	double maxSum=table[0][0];
	*leftUpY = *leftUpX = *rightDownY = *rightDownX = 0;

	/*For all feasible starting points call maxSumConstPoint*/
	for(lUY=0; lUY<nRow; ++lUY){
		for(lUX=0; lUX<COL_COUNT; ++lUX){
			temp=maxSumConstPoint(table, nRow, lUY, lUX, &rDY, &rDX);
			if(temp>maxSum){
				/*a better rectangular found, perform an update*/
				maxSum=temp;
				*leftUpY=lUY;
				*leftUpX=lUX;
				*rightDownY=rDY;
				*rightDownX=rDX;
			}
		}
	}

	return maxSum;



}
