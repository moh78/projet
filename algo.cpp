//#include "graphe.h"
//#include "sommet.h"
//#include "arc.h"

//void  Tarjan(Graphe G){
//  int num = 0;
//  stack <Sommet> pile ;
//  stack <int> partition ;

//   void parcours(Sommet v){
//    v.num = num
//    v.numAccessible = num
//    num = num + 1;
//    pile.push(v);
//    v.dansPile = oui;

//    // Parcours récursif
//    pour chaque w successeur de v
//      si w.num n'est pas défini
//        parcours(w)
//        v.numAccessible = min(v.numAccessible, w.numAccessible)
//      sinon si w.dansP = oui
//        v.numAccessible := min(v.numAccessible, w.num)

//    si v.numAccessible = v.num
//      // v est une racine, on calcule la composante fortement connexe associée
//      C := ensemble vide
//      répéter
//        w := P.pop(), w.dansP := non
//        ajouter w à C
//      tant que w différent de v
//      ajouter C à partition
//  fin de fonction

//  pour chaque sommet v de G
//    si v.num n'est pas défini
//      parcours(v)

//  renvoyer partition
//fin de fonction
