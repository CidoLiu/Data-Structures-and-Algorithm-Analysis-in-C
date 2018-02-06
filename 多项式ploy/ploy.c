/* This code doesn't really do much */
/* Thus I haven't bothered testing it */

#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )


#define MaxDegree 100

static int
Max( int A, int B )
{
    return A > B ? A : B;
}

#if 0

/* START: fig3_18.txt */
        typedef struct
        {
            int CoeffArray[ MaxDegree + 1 ];//ϵ��coefficient
            int HighPower;//��ߴ���
        } *Polynomial;
/* END */

/* START: fig3_19.txt */
        void
        ZeroPolynomial( Polynomial Poly )
        {
            int i;

            for( i = 0; i <= MaxDegree; i++ )
                Poly->CoeffArray[ i ] = 0;
            Poly->HighPower = 0;
        }
/* END */

/* START: fig3_20.txt */
        void
        AddPolynomial( const Polynomial Poly1, const Polynomial Poly2,
                       Polynomial PolySum )
        {
            int i;

            ZeroPolynomial( PolySum );
            PolySum->HighPower = Max( Poly1->HighPower,
                                      Poly2->HighPower );

            for( i = PolySum->HighPower; i >= 0; i-- )
                PolySum->CoeffArray[ i ] = Poly1->CoeffArray[ i ]
                                               + Poly2->CoeffArray[ i ];
        }
/* END */

/* START: fig3_21.txt */
        void
        MultPolynomial( const Polynomial Poly1,
                        const Polynomial Poly2, Polynomial PolyProd )
        {
            int i, j;

            ZeroPolynomial( PolyProd );
            PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

            if( PolyProd->HighPower > MaxDegree )
                Error( "Exceeded array size" );
            else
                for( i = 0; i <= Poly1->HighPower; i++ )
                    for( j = 0; j <= Poly2->HighPower; j++ )
                        PolyProd->CoeffArray[ i + j ] +=
                                Poly1->CoeffArray[ i ] *
                                Poly2->CoeffArray[ j ];
        }
/* END */

void
PrintPoly( const Polynomial Q )
{
    int i;

    for( i = Q->HighPower; i > 0; i-- )
        printf( "%dx^%d + ", Q->CoeffArray[ i ], i );
    printf( "%d\n", Q->CoeffArray[ 0 ] );
}

int main( )
{
    Polynomial P, Q;

    P = malloc( sizeof( *P ) );
    Q = malloc( sizeof( *Q ) );

    P->HighPower = 1; P->CoeffArray[ 0 ] = 1; P->CoeffArray[ 1 ] = 1;
    MultPolynomial( P, P, Q );
    MultPolynomial( Q, Q, P );
    AddPolynomial( P, P, Q );
    PrintPoly( Q );

    return 0;
}

#endif // 0

#if 1
/* START: fig3_23.txt */
        typedef struct Node *PtrToNode;

        struct Node
        {
            int Coefficient;
            int Exponent;
            PtrToNode Next;
        };

        typedef PtrToNode Polynomial;  /* Nodes sorted by exponent */
/* END */

void initPloy(Polynomial P){
    P = malloc( sizeof( *P ) );
    P->Coefficient=0;
    P->Exponent=0;
    P->Next=NULL;
}

int isEmpty(Polynomial P){
    return P->Coefficient==0;
}

//void addNode(Polynomial P,int confficient,int exponent){
//    if(isEmpty(P)){
//        P.Coefficient=confficient;
//        P.Exponent=exponent;
//        P.Next=NULL;
//        return ;
//    }
//    Polynomial temp;
//    temp=malloc(sizeof(struct Node));
//
//}

int main(){
    Polynomial P, Q;
    //initPloy(P);
    P = malloc( sizeof( *P ) );
    P->Coefficient=0;
    P->Exponent=0;
    P->Next=NULL;
    printf("%d\n",P->Coefficient);
    return 0;
}
#endif
