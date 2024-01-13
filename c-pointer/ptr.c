// declare
struct GraphicsObject;

// an instance / object from Graphicsobject
// struct GraphicsObject  x;
   struct GraphicsObject *x;

int main()
{
    char A;
    char *ptrA = &A;
    char *ptrX = ptrA;

    ptrA++;
    ptrA--;
}
