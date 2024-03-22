#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Binary Search Tree tests
    // BinarySearchTree<char,int> bt;
    // bt.insert(std::make_pair('a',1));
    // bt.insert(std::make_pair('b',2));
    
    // cout << "Binary Search Tree contents:" << endl;

    // for(BinarySearchTree<char,int>::iterator it = bt.begin(); it != bt.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // if(bt.find('b') != bt.end()) {
    //     cout << "Found b" << endl;
    // }
    // else {
    //     cout << "Did not find b" << endl;
    // }
    // cout << "Erasing b" << endl;
    // bt.remove('b');
    // bt.clear(); 
    
    // // AVL Tree Tests
    // AVLTree<char,int> at;
    // at.insert(std::make_pair('a',1));
    // at.insert(std::make_pair('b',2));

    // cout << "\nAVLTree contents:" << endl;
    // for(AVLTree<char,int>::iterator it = at.begin(); it != at.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // if(at.find('b') != at.end()) {
    //     cout << "Found b" << endl;
    // }
    // else {
    //     cout << "Did not find b" << endl;
    // }
    // cout << "Erasing b" << endl;
    // at.remove('b');

    // AVL Tree test 1:
    // // Insert 10, 20, 30, 15, 25, 12, 5, 3, 8
    // AVLTree<int, int> tree1; 
    // tree1.insert(std::make_pair(10, 10)); 
    // // tree1.print(); 

    // tree1.insert(std::make_pair(20, 20)); 
    // // tree1.print(); 

    // tree1.insert(std::make_pair(30, 30)); 
    // // tree1.print(); 

    // tree1.insert(std::make_pair(15, 15));
    // // tree1.print(); 

    // tree1.insert(std::make_pair(25, 25)); 
    // // tree1.print(); 

    // tree1.insert(std::make_pair(12, 12));
    // // tree1.print(); 


    // // My left zig-zag is setting null too much or too early

    // tree1.insert(std::make_pair(5, 5)); 
    // // tree1.print(); 

    // // Zig-zig is setting null too much or too early
    // tree1.insert(std::make_pair(3, 3));
    // // tree1.print(); 


    // // When 'zig' in zig-zag, the node is being moved.
    // // make sure the node's children are left behind first 
    // tree1.insert(std::make_pair(8, 8));
    // tree1.print();  

    // // AVL Tree test 2:
    // // Insert: -125, -89, -87, -84, -58, -54, -52, -38, -35, -27, -18, 61, 76, 109, 110, 127, 130, 141, -49
    // // + 126

    // AVLTree<int, int> tree2; 
    // tree2.insert(std::make_pair(-27 + 126,-27));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-52 + 126, -52));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-18 + 126, -18));
    // tree2.print();  
    
    // tree2.insert(std::make_pair(-24 + 126, -24));
    // tree2.print(); 

    // tree2.insert(std::make_pair(109 + 126, 109));
    // tree2.print(); 
    
    // tree2.insert(std::make_pair(-58 + 126, -58));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-49 + 126, -49));
    // tree2.print(); 
    
    // tree2.insert(std::make_pair(127 + 126, 127));
    // tree2.print(); 
 
    // tree2.insert(std::make_pair(9 + 126, 9));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-84 + 126, -84));
    // tree2.print(); 

    // tree2.insert(std::make_pair(141 + 126, 141));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-38 + 126, -38));
    // tree2.print();

    // tree2.insert(std::make_pair(-12 + 126, -12));
    // tree2.print();
    
    // tree2.insert(std::make_pair(48 + 126, 48));
    // tree2.print();

    // tree2.insert(std::make_pair(-89 + 126, -89));
    // tree2.print();
    
    // tree2.insert(std::make_pair(61 + 126, 61));
    // tree2.print();

    // tree2.insert(std::make_pair(87 + 126, 87));
    // tree2.print();

    // tree2.insert(std::make_pair(11 + 126, 11));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-35 + 126, -35));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-87 + 126, -87));
    // tree2.print(); 

    // tree2.insert(std::make_pair(130 + 126, 130));
    // tree2.print(); 

    // tree2.insert(std::make_pair(72 + 126, 72));
    // tree2.print(); 
    
    // tree2.insert(std::make_pair(76 + 126, 76));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-113 + 126, -113));
    // tree2.print(); 

    // tree2.insert(std::make_pair(110 + 126, 110));
    // tree2.print(); 
    
    // tree2.insert(std::make_pair(-54 + 126, -54));
    // tree2.print(); 

    // tree2.insert(std::make_pair(63 + 126, 63));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-126 + 126, -126));
    // tree2.print(); 

    // tree2.insert(std::make_pair(-125 + 126, -125)); 
    // tree2.print(); 

    // AVL Test 3
//     AVLTree<int, int> tree3; 

//    tree3.insert(std::make_pair(-93 + 115, 93));
//    tree3.print(); 

//    tree3.insert(std::make_pair(27 + 115, 27));
//    tree3.print(); 

//    tree3.insert(std::make_pair(1 + 115, 1));
//    tree3.print(); 

//    tree3.insert(std::make_pair(-109 + 115, -109));
//    tree3.print(); 

//    tree3.insert(std::make_pair(62 + 115, 62));
//    tree3.print(); 
   
//    tree3.insert(std::make_pair(37 + 115, 37));
//    tree3.print(); 

//    tree3.insert(std::make_pair(-14 + 115, 14));
//    tree3.print(); 

//    tree3.insert(std::make_pair(135 + 115, -135));
//    tree3.print(); 

//    tree3.insert(std::make_pair(-47 + 115, -47));
//    tree3.print(); 

//    tree3.insert(std::make_pair(-74 + 115, -74));
//    tree3.print(); 

//    tree3.insert(std::make_pair(133 + 115, 133));
//    tree3.print(); 

//    tree3.insert(std::make_pair(-115 + 115, -115));
//    tree3.print(); 

//    tree3.insert(std::make_pair(78 + 115, 78));
//    tree3.print(); 

//     tree3.insert(std::make_pair(-78 + 115, -78));
//    tree3.print(); 

//    tree3.insert(std::make_pair(147 + 115, 147));
//    tree3.print(); 
   //

//    tree3.insert(std::make_pair(-5 + 115, -5));
//    tree3.print(); 

//    tree3.insert(std::make_pair(72 + 115, 72));
//    tree3.print(); 

//    tree3.insert(std::make_pair(-94 + 115, 94));
//    tree3.print(); 

//    tree3.insert(std::make_pair(10 + 115, 10));
//    tree3.print(); 

//    tree3.insert(std::make_pair(28 + 115, 28));
//    tree3.print(); 

//    tree3.insert(std::make_pair(68 + 115, 68));
//    tree3.print(); 

//    tree3.insert(std::make_pair(-64 + 115, -64));
//    tree3.print(); 

//    tree3.insert(std::make_pair(73 + 115, 73));
//    tree3.print(); 

//    tree3.insert(std::make_pair(-62 + 115, -62));
//    tree3.print(); 

//    tree3.insert(std::make_pair(66 + 115, 66));
//    tree3.print(); 

//    tree3.insert(std::make_pair(65 + 115, 65));
//    tree3.print(); 
   
//    tree3.insert(std::make_pair(-40 + 115, -40));
//    tree3.print(); 

//    tree3.insert(std::make_pair(7 + 115, 7));
//    tree3.print(); 

//    tree3.insert(std::make_pair(-102 + 115, -102));
//    tree3.print(); 

//    tree3.insert(std::make_pair(55 + 115, 55));
//    tree3.print(); 

/*
-93
27
1
-109
62
37
-14
135
-47
-74
133
-115
78
-78
147
-5
72
-94
10
28
68
-64
73
-62
66
65
-40
7
-102
55
*/

// AVL Test 4
	// AVLTree<int, double> tree4;
	// tree4.insert(std::make_pair(3, 1.0));
	// tree4.insert(std::make_pair(4, 1.0));
	// tree4.insert(std::make_pair(2, 1.0));
	// tree4.insert(std::make_pair(1, 1.0));


    // tree4.print();

    // tree4.remove(4); 
    // tree4.print();

// AVL Test 5
	// AVLTree<int, double> tree5;
	// tree5.insert(std::make_pair(2, 1.0));
	// tree5.insert(std::make_pair(3, 1.0));
	// tree5.insert(std::make_pair(1, 1.0));
	// tree5.insert(std::make_pair(4, 1.0));
    // tree5.print(); 

	// tree5.remove(1);
    // tree5.print();

// AVL Test 6
/*
INSERT: -53
INSERT: -144
INSERT: -22
INSERT: 56
INSERT: -147
INSERT: 75
INSERT: -128
INSERT: 123
INSERT: -89
INSERT: -117
INSERT: 50
INSERT: 2
INSERT: 114
INSERT: 21
INSERT: 147
INSERT: 45
INSERT: 16
INSERT: 28
INSERT: -64
INSERT: -77
INSERT: -73
INSERT: 71
INSERT: 105
INSERT: 144
INSERT: -20
INSERT: 41
INSERT: -61
INSERT: 106
INSERT: -96
INSERT: -142
REMOVE: -20
-1
CASE 3
CASE 3
CASE 2 Right
REMOVE: -96
1
CASE 3
CASE 2 Right
REMOVE: -89
1
CASE 1 - Right
CASE 1B - Right
CASE 2
*/

    // AVLTree<int, double> tree6;
    // tree6.insert(std::make_pair(-53 + 500, -53));
    // tree6.insert(std::make_pair(-144 + 500, -144));
    // tree6.insert(std::make_pair(-22 + 500, -22));
    // tree6.insert(std::make_pair(56 + 500, 56));
    // tree6.insert(std::make_pair(-147 + 500, -147));
    // tree6.insert(std::make_pair(75 + 500, 75));
    // tree6.insert(std::make_pair(-128 + 500, -128));
    // tree6.insert(std::make_pair(123 + 500, 123));
    // tree6.insert(std::make_pair(-89 + 500, -89));
    // tree6.insert(std::make_pair(-117 + 500, -117));
    // tree6.insert(std::make_pair(50 + 500, 50));
    // tree6.insert(std::make_pair(2 + 500, 2));
    // tree6.insert(std::make_pair(114 + 500, 114));
    // tree6.insert(std::make_pair(21 + 500, 21));
    // tree6.insert(std::make_pair(147 + 500, 147));
    // tree6.insert(std::make_pair(45 + 500, 45));
    // tree6.insert(std::make_pair(16 + 500, 16));
    // tree6.insert(std::make_pair(28 + 500, 28));
    // tree6.insert(std::make_pair(-64 + 500, -64));
    // tree6.insert(std::make_pair(-77 + 500, -77));
    // tree6.insert(std::make_pair(-73 + 500, -73));
    // tree6.insert(std::make_pair(71 + 500, 71));
    // tree6.insert(std::make_pair(105 + 500, 105));
    // tree6.insert(std::make_pair(144 + 500, 144));
    // tree6.insert(std::make_pair(-20 + 500, -20));
    // tree6.insert(std::make_pair(41+ 500, 41));
    // tree6.insert(std::make_pair(-61 + 500, -61));
    // tree6.insert(std::make_pair(106 + 500, 106));
    // tree6.insert(std::make_pair(-96 + 500, -96));
    // tree6.insert(std::make_pair(-142 + 500, -142));
    // // tree6.insert(std::make_pair(-20 + 500, -20));

    // tree6.remove(-20 + 500); 
    // tree6.print(); 

    // tree6.remove(-96 + 500);
    // tree6.print(); 

    // tree6.remove(-89 + 500);
    // tree6.print(); 

    // tree6.remove(16 + 500); 
    // tree6.print(); 

    // tree6.remove(56 + 500);
    // tree6.print();

    // tree6.remove(144 + 500);
    // tree6.print();

    // tree6.remove(105 + 500);
    // tree6.print();

    // tree6.remove(-144 + 500);
    // tree6.print();

    // tree6.remove(-22 + 500);
    // tree6.print();

    // tree6.remove(-117 + 500);
    // tree6.print();

    // tree6.remove(45 + 500);
    // tree6.print();

    // tree6.remove(-77 + 500);
    // tree6.print();

    // tree6.remove(-128 + 500);
    // tree6.print();

    //     tree6.remove(21 + 500);
    // tree6.print();

    //         tree6.remove(114 + 500);
    // tree6.print();

    //         tree6.remove(123 + 500);
    // tree6.print();

    //         tree6.remove(41 + 500);
    // tree6.print();

    //         tree6.remove(-147 + 500);
    // tree6.print();

    //         tree6.remove(-61 + 500);
    // tree6.print();


    //         tree6.remove(-65 + 500);
    // tree6.print();


    //         tree6.remove(-86 + 500);
    // tree6.print();

    //             tree6.remove(-58 + 500);
    // tree6.print();

    

    /*
    REMOVE: -20
REMOVE: -96
REMOVE: -89
REMOVE: 16
REMOVE: 56
REMOVE: 144
REMOVE: 105
REMOVE: -144
REMOVE: -22
REMOVE: -117
REMOVE: 45
REMOVE: -77
REMOVE: -128
REMOVE: 21
    */

    // Test 7 
    /*
    INSERT: 2
INSERT: 3
INSERT: 1
INSERT: 4
REMOVE: 1
    */

//    AVLTree<int, double> tree7;
//    tree7.insert(std::make_pair(2, 2));
//    tree7.insert(std::make_pair(3, 3));
//    tree7.insert(std::make_pair(1, 1));
//    tree7.insert(std::make_pair(4, 4));

//    tree7.print();

//    tree7.remove(1);
//    tree7.print();


AVLTree<int, double> tree8;
// tree8.insert(std::make_pair(146 + 500, 146));
// tree8.insert(std::make_pair(-2 + 500, -2));
// tree8.insert(std::make_pair(-51 + 500, -51));
// tree8.insert(std::make_pair(99 + 500, 99));
// tree8.insert(std::make_pair(-8 + 500, -8));
// tree8.insert(std::make_pair(134 + 500, 134));
// tree8.insert(std::make_pair(-79 + 500, -79));
// tree8.insert(std::make_pair(73 + 500, 73));
// tree8.insert(std::make_pair(-58 + 500, -58));
// tree8.insert(std::make_pair(70 + 500, 70));
// tree8.insert(std::make_pair(-81 + 500, -81));
// tree8.insert(std::make_pair(-65 + 500, -65));
// tree8.insert(std::make_pair(149 + 500, 149));
// tree8.insert(std::make_pair(-72 + 500, -72));
// tree8.insert(std::make_pair(79 + 500, 79));
// tree8.insert(std::make_pair(-121 + 500, -121));
// tree8.insert(std::make_pair(-24 + 500, -24));
// tree8.insert(std::make_pair(-118 + 500, -118));
// tree8.insert(std::make_pair(-86 + 500, -86));
// tree8.insert(std::make_pair(81 + 500, 81));
// tree8.insert(std::make_pair(-82 + 500, -82));
// tree8.insert(std::make_pair(-46 + 500, -46));
// tree8.insert(std::make_pair(150 + 500, 150));
// tree8.insert(std::make_pair(83 + 500, 83));
// tree8.insert(std::make_pair(133 + 500, 133));
// tree8.insert(std::make_pair(-101 + 500, -101));
// tree8.insert(std::make_pair(-61 + 500, -61));
// tree8.insert(std::make_pair(-90 + 500, -90));
// tree8.insert(std::make_pair(90 + 500, 90));
// tree8.insert(std::make_pair(127 + 500, 127));
// tree8.insert(std::make_pair(-82 + 500, -82));
// tree8.print();


//     tree8.remove(-82 + 500);
//     tree8.print();

//     tree8.remove(-121 + 500);
//     tree8.print();
    
// tree8.remove(146 + 500);
// tree8.print();

//     tree8.remove(-8 + 500);
//     tree8.print();

//     tree8.remove(-81 + 500);
//     tree8.print();

//         tree8.remove(-90 + 500);
//     tree8.print();

//         tree8.remove(149 + 500);
//     tree8.print();

//         tree8.remove(83 + 500);
//     tree8.print();

//         tree8.remove(-61 + 500);
//     tree8.print();

//         tree8.remove(-65 + 500);
//     tree8.print();

//         tree8.remove(-86 + 500);
//     tree8.print();

//         tree8.remove(-58 + 500);
//     tree8.print();

//             tree8.remove(79 + 500);
//     tree8.print();

//             tree8.remove(-79 + 500);
//     tree8.print();

//             tree8.remove(73 + 500);
//     tree8.print();

//             tree8.remove(127 + 500);
//     tree8.print();

//             tree8.remove(90+ 500);
//     tree8.print();

//             tree8.remove(150 + 500);
//     tree8.print();


//             tree8.remove(-101 + 500);
//     tree8.print();


//             tree8.remove(134 + 500);
//     tree8.print();

//             tree8.remove(-24 + 500);
//     tree8.print();


// AVLTree<int, double> tree9;
// tree9.insert(std::make_pair(-11 + 500, 146));
// tree9.insert(std::make_pair(-140 + 500, 146));
// tree9.insert(std::make_pair(86 + 500, 146));
// tree9.insert(std::make_pair(-77 + 500, 146));
// tree9.insert(std::make_pair(75 + 500, 146));
// tree9.insert(std::make_pair(12 + 500, 146));
// tree9.insert(std::make_pair(51 + 500, 146));
// tree9.insert(std::make_pair(128 + 500, 146));
// tree9.insert(std::make_pair(135 + 500, 146));
// tree9.insert(std::make_pair(-26 + 500, 146));
// tree9.insert(std::make_pair(-104 + 500, 146));
// tree9.insert(std::make_pair(149 + 500, 146));
// tree9.insert(std::make_pair(73 + 500, 146));
// tree9.insert(std::make_pair(48 + 500, 146));
// tree9.insert(std::make_pair(14 + 500, 146));
// tree9.insert(std::make_pair(-115 + 500, 146));
// tree9.insert(std::make_pair(57 + 500, 146));
// tree9.insert(std::make_pair(118 + 500, 146));
// tree9.insert(std::make_pair(-109 + 500, 146));
// tree9.insert(std::make_pair(-120 + 500, 146));
// tree9.insert(std::make_pair(43 + 500, 146));
// tree9.insert(std::make_pair(-5 + 500, 146));
// tree9.insert(std::make_pair(122 + 500, 146));
// tree9.insert(std::make_pair(-37 + 500, 146));
// tree9.insert(std::make_pair(83 + 500, 146));
// tree9.insert(std::make_pair(-53 + 500, 146));
// tree9.insert(std::make_pair(16 + 500, 146));
// tree9.insert(std::make_pair(107 + 500, 146));
// tree9.insert(std::make_pair(88 + 500, 146));
// tree9.insert(std::make_pair(18 + 500, 146));

// // tree9.insert(std::make_pair(-11 + 500, 146));
// tree9.print();

// tree9.remove(-104 + 500);
// tree9.print();

// tree9.remove(-5 + 500);
// tree9.print();

// tree9.remove(-11 + 500);
// tree9.print();

// tree9.remove(75 + 500);
// tree9.print();

// tree9.remove(-120 + 500);
// tree9.print();

// tree9.remove(-115 + 500);
// tree9.print();

// tree9.remove(-53 + 500);
// tree9.print();

// tree9.remove(128 + 500);
// tree9.print();

// tree9.remove(149 + 500);
// tree9.print();
// //

// tree9.remove(18 + 500);
// tree9.print();

// tree9.remove(-26 + 500);
// tree9.print();

// tree9.remove(-37 + 500);
// tree9.print();

// tree9.remove(12 + 500);
// tree9.print();

// tree9.remove(-77 + 500);
// tree9.print();

// tree9.remove(73 + 500);
// tree9.print();

// tree9.remove(57 + 500);
// tree9.print();

// tree9.remove(118 + 500);
// tree9.print();

// tree9.remove(-140 + 500);
// tree9.print();
// //

// tree9.remove(-109 + 500);
// tree9.print();

// tree9.remove(48 + 500);
// tree9.print();

// tree9.remove(135 + 500);
// tree9.print();

// tree9.remove(14 + 500);
// tree9.print();

// tree9.remove(107 + 500);
// tree9.print();

// tree9.remove(16 + 500);
// tree9.print();

// tree9.remove(86 + 500);
// tree9.print();

// // Left child of 51 doens't have parent set properly
// tree9.remove(83 + 500);
// tree9.print();

// tree9.remove(-140 + 500);
// tree9.print();


// AVLTree<int, double> tree10; 
// // INSERT: 0
// // INSERT: 73
// // INSERT: -83
// // INSERT: -104
// // INSERT: -14
// // INSERT: 97
// // INSERT: 15
// // INSERT: -68
// // INSERT: 121
// // INSERT: -4
// // INSERT: 16
// // INSERT: 21
// // INSERT: -31
// // INSERT: 13
// // INSERT: -73
// // INSERT: -96
// // INSERT: -136
// // INSERT: 131
// // INSERT: 86
// // INSERT: 55
// // INSERT: 74
// // INSERT: 8
// // INSERT: 109
// // INSERT: -15
// // INSERT: -124
// // INSERT: 119
// // INSERT: 10
// // INSERT: -145
// // INSERT: 82
// // INSERT: -129

// // REMOVE: -4
// tree10.insert(std::make_pair(0 + 500, 146));
// tree10.insert(std::make_pair(73 + 500, 146));
// tree10.insert(std::make_pair(-83 + 500, 146));
// tree10.insert(std::make_pair(-104 + 500, 146));
// tree10.insert(std::make_pair(-14 + 500, 146));
// tree10.insert(std::make_pair(97 + 500, 146));
// tree10.insert(std::make_pair(15+ 500, 146));
// tree10.insert(std::make_pair(-68 + 500, 146));
// tree10.insert(std::make_pair(121 + 500, 146));
// tree10.insert(std::make_pair(-4 + 500, 146));
// tree10.insert(std::make_pair(16 + 500, 146));
// tree10.insert(std::make_pair(21 + 500, 146));
// tree10.insert(std::make_pair(-31 + 500, 146));
// tree10.insert(std::make_pair(13 + 500, 146));
// tree10.insert(std::make_pair(-73 + 500, 146));
// tree10.insert(std::make_pair(-96 + 500, 146));
// tree10.insert(std::make_pair(-136 + 500, 146));
// tree10.insert(std::make_pair(131 + 500, 146));
// tree10.insert(std::make_pair(86 + 500, 146));
// tree10.insert(std::make_pair(55 + 500, 146));
// tree10.insert(std::make_pair(74 + 500, 146));
// tree10.insert(std::make_pair(8 + 500, 146));
// tree10.insert(std::make_pair(109 + 500, 146));
// tree10.insert(std::make_pair(-15 + 500, 146));
// tree10.insert(std::make_pair(-124 + 500, 146));
// tree10.insert(std::make_pair(119 + 500, 146));
// tree10.insert(std::make_pair(10 + 500, 146));
// tree10.insert(std::make_pair(-145 + 500, 146));
// tree10.insert(std::make_pair(82 + 500, 146));
// tree10.insert(std::make_pair(-129 + 500, 146));

// tree10.print(); 

// tree10.remove(-4 + 500);
// tree10.print();

// tree10.remove(-104 + 500);
// tree10.print();

// tree10.remove(16 + 500);
// tree10.print();

// tree10.remove(13 + 500);
// tree10.print();

// tree10.remove(-15 + 500);
// tree10.print();

// tree10.remove(-129 + 500);
// tree10.print();

// tree10.remove(-136 + 500);
// tree10.print();

// tree10.remove(-96 + 500);
// tree10.print();

// tree10.remove(119 + 500);
// tree10.print();

// tree10.remove(21 + 500);
// tree10.print();

// tree10.remove(-124 + 500);
// tree10.print();

// tree10.remove(97 + 500);
// tree10.print();

// tree10.remove(-68 + 500);
// tree10.print();

// tree10.remove(121 + 500);
// tree10.print();

// tree10.remove(-73 + 500);
// tree10.print();

// tree10.remove(-14 + 500);
// tree10.print();

// tree10.remove(-145 + 500);
// tree10.print();

// tree10.remove(10 + 500);
// tree10.print();

// tree10.remove(-83 + 500);
// tree10.print();

// tree10.remove(15 + 500);
// tree10.print();

// tree10.remove(109 + 500);
// tree10.print();

// tree10.remove(86 + 500);
// tree10.print();

// tree10.remove(0 + 500);
// tree10.print();

// tree10.remove(73 + 500);
// tree10.print();

// tree10.remove(-31 + 500);
// tree10.print();

// tree10.remove(74 + 500);
// tree10.print();

// tree10.remove(55 + 500);
// tree10.print();

AVLTree<int, double> tree11;
/*
INSERT: 45
INSERT: -48
INSERT: -109
INSERT: -1
INSERT: 40
INSERT: 133
INSERT: 90
INSERT: -6
INSERT: -135
INSERT: -88
INSERT: 86
INSERT: 22
INSERT: -107
INSERT: -146
INSERT: -131
INSERT: -113
INSERT: -148
INSERT: 10
INSERT: -22
INSERT: -17
INSERT: -12
INSERT: 122
INSERT: -63
INSERT: -39
INSERT: -31
INSERT: 43
INSERT: 118
INSERT: -64
INSERT: -118
INSERT: -71
*/ 
tree11.insert(std::make_pair(45 + 500, 146));
tree11.insert(std::make_pair(-48 + 500, 146));
tree11.insert(std::make_pair(-109 + 500, 146));
tree11.insert(std::make_pair(-1+ 500, 146));
tree11.insert(std::make_pair(40+ 500, 146));
tree11.insert(std::make_pair(133+ 500, 146));
tree11.insert(std::make_pair(90+ 500, 146));
tree11.insert(std::make_pair(-6 + 500, 146));
tree11.insert(std::make_pair(-135+ 500, 146));
tree11.insert(std::make_pair(-88 + 500, 146));
tree11.insert(std::make_pair(86 + 500, 146));
tree11.insert(std::make_pair(22 + 500, 146));
tree11.insert(std::make_pair(-107 + 500, 146));
tree11.insert(std::make_pair(-146 + 500, 146));
tree11.insert(std::make_pair(-131 + 500, 146));
tree11.insert(std::make_pair(-113 + 500, 146));
tree11.insert(std::make_pair(-148 + 500, 146));
tree11.insert(std::make_pair(10 + 500, 146));
tree11.insert(std::make_pair(-22 + 500, 146));
tree11.insert(std::make_pair(-17 + 500, 146));
tree11.insert(std::make_pair(-12 + 500, 146));
tree11.insert(std::make_pair(122 + 500, 146));
tree11.insert(std::make_pair(-63 + 500, 146));
tree11.insert(std::make_pair(-39 + 500, 146));
tree11.insert(std::make_pair(-31 + 500, 146));
tree11.insert(std::make_pair(43 + 500, 146));
tree11.insert(std::make_pair(118 + 500, 146));
tree11.insert(std::make_pair(-64 + 500, 146));
tree11.insert(std::make_pair(-118 + 500, 146));
tree11.insert(std::make_pair(-71+ 500, 146));
tree11.print();

tree11.remove(-146 + 500);
tree11.remove(122 + 500);
tree11.remove(-131 + 500);
tree11.remove(90 + 500);
tree11.remove(-31 + 500);
tree11.remove(-113 + 500);
tree11.remove(10 + 500);
tree11.remove(-39 + 500);
tree11.remove(-48 + 500);
tree11.remove(-88 + 500);
tree11.remove(-17 + 500);
tree11.remove(-109 + 500);
tree11.remove(45 + 500);
tree11.remove(-135 + 500);
tree11.remove(-63 + 500);
tree11.remove(86 + 500);
tree11.remove(-118 + 500);
tree11.print(); 
    return 0; 

}