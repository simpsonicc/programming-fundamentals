#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dot{
     int type;
     float x; 
     float y;
} dot; // dot struct

typedef struct line{
    int type;
    float x1;
    float y1;
    float x2;
    float y2;
} line; // line struct

typedef struct triangle{
    int type;
    float x1;
    float y1;
    float x2;
    float y2;
    float x3; 
    float y3;
} triangle; // triangle struct 

typedef struct square{
    int type;
    float x1;
    float y1;
    float x2;
    float y2;
} square; // square struct 

typedef struct rectangle{
    int type;
    float x;
    float y;
    float width;
    float height;
} rectangle; // rectangle struct

float calculateProperty(void *shapePtr, int propertyType);

int main(){
    dot *d = calloc(1, sizeof(dot));
    d->type = 0;
    d->x = 9.0;
    d->y = 9.0;
    line *l = calloc(1, sizeof(line));
    l->type = 1;
    l->x1 = 5.6;
    l->y1 = 3.2;
    l->x2 = 9.6;
    l->y2 = 10.8;
    triangle *t= calloc(1, sizeof(triangle));
    t->type = 2;
    t->x1 = 5.6;
    t->y1 = 3.2;
    t->x2 = 9.6;
    t->y2 = 10.8;
    t->x3 = 15.5;
    t->y3 = 3.2;
    square *s = calloc(1, sizeof(square));
    s->type = 3;
    s->x1 = 10.0;
    s->y1 = 10.0;
    s->x2 = 3.6;
    s->y2 = 6.9;
    rectangle *r = calloc(1, sizeof(rectangle));
    r->type = 4;
    r->x = 8.0;
    r->y = 9.0;
    r->width = 20.5;
    r->height = 8.9;

    void *shapes[5] = {d, l, t, s, r}; // d,l... are addresses themselves
    // printf("%x", shapes[3]);
    for (int i =0; i<5; i++){
        printf("Area: %.2f\n",calculateProperty(shapes[i], 1));
        printf("Perimeter/length: %.2f\n", calculateProperty(shapes[i], 2));
        printf("distance from origin: %.2f\n", calculateProperty(shapes[i], 3));
    }

    for (int i = 0; i<5; i++){
        free(shapes[i]);
    }
    return 0;
}

float calculateProperty(void *shapePtr, int propertyType){ // for propertytype, 1 is for area, 2 is for perimeter/length, and 3 is for distance from origin
    int shapetype = *(int *)shapePtr; // shapeptr is the address that holds a value, we tell it that value is the int and get it using derefrencing
    // we need the type 
    switch (shapetype)
    {
    case 0: // dot so give out its distance from the origin
        dot *d = (dot *)shapePtr; // type cast
        printf("Point\n");
        if ((propertyType == 1) || (propertyType == 2)) return 0.0;// dot cannot have an area or perimeter
        return sqrt(pow((d->x), 2.0)+pow((d->y), 2.0)); // returns the ditance from the origin
        break;
    case 1: // line
        line *l = (line *)shapePtr;
        printf("Line\n");
        if (propertyType == 1) return 0.0; // line does not have an area
        if (propertyType == 2){
            return sqrt(pow(((l->x2)-(l->x1)), 2.0) + pow(((l->y2) - (l->y1)), 2.0));
        }
        else if (propertyType == 3) return sqrt(pow((l->x1), 2.0) + pow((l->y1), 2.0)); // distance from origin to (x1, y1)
        break;
    case 2: // triangle
        triangle *t = (triangle *)shapePtr;
        printf("Triangle\n");
        if (propertyType == 3) return sqrt(pow((t->x1), 2.0)+pow((t->y1), 2.0)); // distance from origin to (x1, y1)
        float s1 = sqrt(pow(((t->x2)-(t->x1)), 2.0) + pow(((t->y2) - (t->y1)), 2.0)); // side 1 length
        float s2 = sqrt(pow(((t->x3)-(t->x1)), 2.0) + pow(((t->y3) - (t->y1)), 2.0)); // side 2 length 
        float s3 = sqrt((pow((t->x3)-(t->x2), 2.0)) + pow(((t->y3) - (t->y2)), 2.0)); // side 3 length
        if (propertyType == 2){ // perimeter
            return s1+s2+s3;
        }
        else if (propertyType == 1){ // area using herons formula
            float s = (s1+s2+s3)/2; // semi perimeter
            return sqrt(s*(s-s1)*(s-s2)*(s-s3));
        }
        break;
    case 3: // sqaure 
        square *s = (square *)shapePtr;
        printf("Square\n");
        if (propertyType == 3) return sqrt(pow((s->x1), 2.0) + pow((s->y1), 2.0)); // distance from origin to (x1, y1)
        float side = sqrt(pow(((s->x2) - (s->x1)), 2.0) + pow(((s->y2) - (s->y1)), 2.0));
        if (propertyType == 1) return side*side;// area
        else if (propertyType == 2) return 4*side; // perimeter
        break;
    case 4: // rectangle 
        rectangle *r = (rectangle *)shapePtr;
        printf("Rectangle\n");
        if (propertyType == 3) return sqrt(pow((r->x), 2.0) + pow((r->y), 2.0));
        else if (propertyType == 1) return (r->height)*(r->width); // area
        else if (propertyType == 2) return (2*(r->height)) + (2*(r->width)); // perimeter
        break;
    default:
        return 0.0;
        break;
    }
    return 0.0;
}