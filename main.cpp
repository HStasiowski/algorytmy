// Wyszukiwanie mediany
// Data:   21.05.2008
// (C)2020 mgr Jerzy Wa�aszek
//---------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 99;

// Funkcja dzieli podany zbi�r Z na dwie partycje:
// ZL - elementy mniejsze od elementu zwrotnego
// ZP - elementy wi�ksze od elementu zwrotnego
// Zwraca pozycj� elementu zwrotnego
//------------------------------------------------
int Dziel_na_partycje ( int * Z, int ip, int ik )
{
  int i, v, x;

  v = Z [ ip ]; i = ip; ik++;
  while( i < ik )
  {
    while( Z [ ++i ]  < v ) ;
    while( Z [ --ik ] > v ) ;
    if( i < ik )
    {
      x = Z [ i ]; Z [ i ] = Z [ ik ]; Z [ ik ] = x;
    }
  }
  Z [ ip ] = Z [ ik ]; Z [ ik ] = v;
  return ik;
}

// Procedura sortuje rosn�co podany zbi�r
//---------------------------------------
void Sortuj_szybko ( int * Z, int ip, int ik )
{
  int iv;

  iv = Dziel_na_partycje ( Z, ip, ik );

  for(int i=0;i<N;i++) cout<<setw(4)<<Z[i];
  cout<<endl<<endl;
  if( ip < iv - 1 ) Sortuj_szybko ( Z, ip, iv - 1 );
  if( ik > iv + 1 ) Sortuj_szybko ( Z, iv + 1, ik );
}

int main( )
{
  int Z [ N + 1 ], i, ip, ik, k, pv;

  srand ( ( unsigned )time ( NULL ) );

  // Przygotowujemy tablic� Z [ ]

  for( i = 0; i < N; i++ ) Z [ i ] = rand( ) % 1000;

  // Na ko�cu Z [ ] umieszczamy wartownika

  Z [ N ] = 1000;

  // Wy�wietlamy Z [ ] przed podzia�em

  for( i = 0; i < N; i++ ) cout << setw ( 4 ) << Z [ i ];
  cout << endl << endl;

  // Sortujemy szybko tablic� Z [ ]

  Sortuj_szybko ( Z, 0, N - 1 );

  // Wy�wietlamy Z [ ] po sortowaniu

  for( i = 0; i < N; i++ ) cout << setw ( 4 ) << Z [ i ];
  cout << endl << endl;

  // Wy�wietlamy median�

  cout << Z [ N >> 1 ] << endl << endl;
  getchar();
  return 0;
}
