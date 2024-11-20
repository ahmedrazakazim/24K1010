#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} Point;

float calculateDistance(Point a, Point b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int isInsideRectangle(Point p, Point topLeft, Point bottomRight)
{
    return (p.x >= topLeft.x && p.x <= bottomRight.x &&
            p.y <= topLeft.y && p.y >= bottomRight.y);
}

int main()
{
    Point firstPoint, secondPoint, testPoint, rectTopLeft, rectBottomRight;

    printf("Enter coordinates of the first point (x1 y1): ");
    scanf("%d %d", &firstPoint.x, &firstPoint.y);

    printf("Enter coordinates of the second point (x2 y2): ");
    scanf("%d %d", &secondPoint.x, &secondPoint.y);

    float distance = calculateDistance(firstPoint, secondPoint);
    printf("Distance between points: %.2f\n", distance);

    printf("Enter top-left corner of the rectangle (x y): ");
    scanf("%d %d", &rectTopLeft.x, &rectTopLeft.y);

    printf("Enter bottom-right corner of the rectangle (x y): ");
    scanf("%d %d", &rectBottomRight.x, &rectBottomRight.y);

    printf("Enter point (x y): ");
    scanf("%d %d", &testPoint.x, &testPoint.y);

    if (isInsideRectangle(testPoint, rectTopLeft, rectBottomRight))
    {
        printf("Inside rectangle.\n");
    }
    else
    {
        printf("Outside rectangle.\n");
    }

    return 0;
}
