// // HashMapTests.cpp
// //
// // ICS 45C Spring 2020
// // Project #3: Maps and Legends
// //
// // Write unit tests for your HashMap class here.  I've provided a few tests
// // already, though I've commented them out, because they won't compile and
// // link until you've implemented some things.
// //
// // Of course, you'll want to write lots more of these tests yourself, because
// // this is an inexpensive way to know whether things are working the way
// // you expect -- including scenarios that you won't happen to hit in the
// // course of testing your overall program.  (You might also want to be sure
// // that your HashMap implementation is complete and correct before you try
// // to write the rest of the program around it, anyway; there's a very
// // substantial amount of partial credit available if all that works is
// // HashMap.)

#include <gtest/gtest.h>
#include <string>
#include "HashMap.hpp"


// TEST(HashMapTests, sizeOfNewlyCreatedHashMapIsZero)
// {
//    HashMap empty;
//    ASSERT_EQ(0, empty.size());
// }


// TEST(HashMapTests, emptyMapContainsNoKeys)
// {
//    HashMap empty;
//    ASSERT_FALSE(empty.contains("first"));
//    ASSERT_FALSE(empty.contains("second"));
//    ASSERT_FALSE(empty.contains(""));
// }


// TEST(HashMapTests, DefaultHashMapAddValContainSize)
// {
//    HashMap hm;
//    hm.add("Boo", "perfect");
//    hm.add("arian", "here");
//    hm.add("was", "123");
//    ASSERT_TRUE(hm.contains("Boo"));
//    ASSERT_TRUE(hm.contains("arian"));
//    ASSERT_TRUE(hm.contains("was"));
//    ASSERT_FALSE(hm.contains("NON_EXISTENT_KEY"));
//    ASSERT_EQ(3,hm.size());  
//    hm.add("Bool", "trues");
//    hm.add("dj", "khaled");
//    hm.add("daft", "punk");
//    ASSERT_TRUE(hm.contains("Bool"));
//    ASSERT_TRUE(hm.contains("dj"));
//    ASSERT_TRUE(hm.contains("daft"));
//    ASSERT_EQ("trues", hm.value("Bool"));
//    ASSERT_EQ("khaled", hm.value("dj"));
//    ASSERT_EQ("punk", hm.value("daft"));
//    ASSERT_EQ("", hm.value("NON_EXISTENT_KEY2"));
//    ASSERT_EQ(6,hm.size());
//    // hm.remove("Boo");
//    // ASSERT_FALSE(hm.remove("asdf"));
//    // ASSERT_FALSE(hm.contains("Boo"));
//    // ASSERT_EQ(5,hm.size());
//    // hm.remove("dj");
//    // ASSERT_TRUE(hm.contains("Bool"));
//    // ASSERT_EQ(4,hm.size());

//    hm.add("Eric", "Cartman");
//    hm.add("Linkin Park", "New Divide");
//    hm.add("System.Down", "ChopSuey");
//    hm.add("Nirvana", "TeenSpirit");
//    ASSERT_TRUE(hm.contains("Linkin Park"));
//    ASSERT_TRUE(hm.contains("System.Down"));
//    ASSERT_TRUE(hm.contains("Nirvana"));
//    ASSERT_TRUE(hm.contains("Eric"));
//    ASSERT_EQ("New Divide", hm.value("Linkin Park"));
//    ASSERT_EQ("ChopSuey", hm.value("System.Down"));
//    ASSERT_EQ("TeenSpirit", hm.value("Nirvana"));
//    ASSERT_EQ("Cartman", hm.value("Eric"));

// }


// namespace
// {
//    unsigned int SDBMHash(std::string s) {
//       unsigned int hash = 0;
//       unsigned int i = 0;
//       unsigned int len = s.length();

//       for (i = 0; i < len; i++)
//       {
//          hash = (s[i]) + (hash << 6) + (hash << 16) - hash;
//       }

//       return hash;
//    }
// }

// TEST(HashMapTests, TestingHashMapWITHArgument)
// {
//    HashMap hm(SDBMHash);
//    hm.add("Boo", "perfect");
//    hm.add("arian", "here");
//    hm.add("was", "123");
//    ASSERT_TRUE(hm.contains("Boo"));
//    ASSERT_TRUE(hm.contains("arian"));
//    ASSERT_TRUE(hm.contains("was"));
//    ASSERT_FALSE(hm.contains("NON_EXISTENT_KEY"));
//    ASSERT_EQ(3,hm.size());
   

//    hm.add("Bool", "trues");
//    hm.add("dj", "khaled");
//    hm.add("daft", "punk");
//    ASSERT_TRUE(hm.contains("Bool"));
//    ASSERT_TRUE(hm.contains("dj"));
//    ASSERT_TRUE(hm.contains("daft"));
//    ASSERT_EQ("trues", hm.value("Bool"));
//    ASSERT_EQ("khaled", hm.value("dj"));
//    ASSERT_EQ("punk", hm.value("daft"));
//    ASSERT_EQ("", hm.value("NON_EXISTENT_KEY2"));
//    ASSERT_EQ(6,hm.size());
//    hm.remove("Boo");
//    ASSERT_FALSE(hm.remove("asdf"));
   
//    ASSERT_FALSE(hm.contains("Boo"));
//    ASSERT_EQ(5,hm.size());
//    hm.remove("dj");
//    ASSERT_TRUE(hm.contains("Bool"));
//    ASSERT_EQ(4,hm.size());


// }

// TEST (HashMapTests, CopyCons)
// {
//     HashMap hm;
//     hm.add("Boo", "perfect");
//     hm.add("Eric", "Cartman");
//     hm.add("Stan", "Marsh");
//     hm.add("Randy", "Marsh");
//     hm.add("Butters", "Stotch");
//     hm.add("Kenny", "Something");
//     hm.add("Alex", "Thortnton");
//     hm.add("Rich", "Pattis");
//     hm.add("CPP", "Hard");
//     hm.add("Rick", "Sanchez");
//     ASSERT_EQ(10,hm.size());
//     HashMap hm2 = hm;
//     ASSERT_TRUE(hm2.contains("Stan"));
//     ASSERT_TRUE(hm2.contains("Eric"));
//     ASSERT_TRUE(hm2.contains("Boo"));
//     ASSERT_TRUE(hm2.contains("Randy"));
//     ASSERT_TRUE(hm2.contains("Butters"));
//     ASSERT_TRUE(hm2.contains("Kenny"));
//     ASSERT_TRUE(hm2.contains("Alex"));
//     ASSERT_TRUE(hm2.contains("Rich"));
//     ASSERT_TRUE(hm2.contains("CPP"));
//     ASSERT_TRUE(hm2.contains("Rick"));
// }

// TEST(HashMapTests, TestCopyCons)
// {
//    HashMap hm;
//    hm.add("Boo", "perfect");
//    hm.add("arian", "here");
//    hm.add("was", "123");
//    ASSERT_TRUE(hm.contains("Boo"));
//    ASSERT_TRUE(hm.contains("arian"));
//    ASSERT_TRUE(hm.contains("was"));
//    ASSERT_FALSE(hm.contains("NON_EXISTENT_KEY"));
//    ASSERT_EQ(3,hm.size());  
//    hm.add("Bool", "trues");
//    hm.add("dj", "khaled");
//    hm.add("daft", "punk");
//    ASSERT_TRUE(hm.contains("Bool"));
//    ASSERT_TRUE(hm.contains("dj"));
//    ASSERT_TRUE(hm.contains("daft"));
//    ASSERT_EQ("trues", hm.value("Bool"));
//    ASSERT_EQ("khaled", hm.value("dj"));
//    ASSERT_EQ("punk", hm.value("daft"));
//    ASSERT_EQ("", hm.value("NON_EXISTENT_KEY2"));
//    ASSERT_EQ(6,hm.size());

//    hm.add("Eric", "Cartman");
//    hm.add("Linkin Park", "New Divide");
//    hm.add("System.Down", "ChopSuey");
//    hm.add("Nirvana", "TeenSpirit");
//    ASSERT_TRUE(hm.contains("Linkin Park"));
//    ASSERT_TRUE(hm.contains("System.Down"));
//    ASSERT_TRUE(hm.contains("Nirvana"));
//    ASSERT_TRUE(hm.contains("Eric"));
//    ASSERT_EQ("New Divide", hm.value("Linkin Park"));
//    ASSERT_EQ("ChopSuey", hm.value("System.Down"));
//    ASSERT_EQ("TeenSpirit", hm.value("Nirvana"));
//    ASSERT_EQ("Cartman", hm.value("Eric"));

//    HashMap hm2 = hm;
//    ASSERT_EQ(10,hm2.size());
//    ASSERT_TRUE(hm2.contains("Linkin Park"));
//    ASSERT_TRUE(hm2.contains("System.Down"));
//    ASSERT_TRUE(hm2.contains("Nirvana"));
//    ASSERT_TRUE(hm2.contains("Eric"));
//    ASSERT_EQ("New Divide", hm2.value("Linkin Park"));
//    ASSERT_EQ("ChopSuey", hm2.value("System.Down"));
//    ASSERT_EQ("TeenSpirit", hm2.value("Nirvana"));
//    ASSERT_EQ("Cartman", hm2.value("Eric"));
//    ASSERT_TRUE(hm2.contains("Bool"));
//    ASSERT_TRUE(hm2.contains("dj"));
//    ASSERT_TRUE(hm2.contains("daft"));
//    ASSERT_EQ("trues", hm2.value("Bool"));
//    ASSERT_EQ("khaled", hm2.value("dj"));
//    ASSERT_EQ("punk", hm2.value("daft"));
//    ASSERT_EQ("", hm2.value("NON_EXISTENT_KEY2"));
//    ASSERT_TRUE(hm2.contains("Boo"));
//    ASSERT_TRUE(hm2.contains("arian"));
//    ASSERT_TRUE(hm2.contains("was"));
//    ASSERT_FALSE(hm2.contains("NON_EXISTENT_KEY"));

   
   

//    // _-----------------------_______________----------___________------
//    //  HashMap hm;
//    //  hm.add("arian", "Here");
//    //  hm.add("gar", "345");
//    //  hm.add("terry", "678");

//    //  HashMap hm2 = hm;
//    //  ASSERT_EQ(3, hm2.size());
//    //  ASSERT_TRUE(hm2.contains("arian"));
//    //  ASSERT_TRUE(hm2.contains("gar"));
//    //  ASSERT_TRUE(hm2.contains("terry"));
    
// }


TEST(HashMapTests,  TestAssignmentCopy)
{
    HashMap hm, hm2;
    hm.add("arian", "123");
    hm.add("gar", "345");
    hm.add("terry", "678");
    
    

    hm2 = hm;
    ASSERT_EQ(3, hm2.size());
    ASSERT_TRUE(hm2.contains("arian"));
    ASSERT_TRUE(hm2.contains("gar"));
    ASSERT_TRUE(hm2.contains("terry"));
    hm2.add("France", "Paris");
    ASSERT_TRUE(hm2.contains("France"));
    ASSERT_EQ("Paris",hm2.value("France"));
    ASSERT_EQ(4,hm2.size());
    ASSERT_EQ(3,hm.size());

}



// TEST(SMALLHashMapTests,  bucketCountIsRightBeforeReHash)
// {
//    HashMap hm;
//    hm.add("Arian", "AA");
//    hm.add("Eric", "Cartman");
//    ASSERT_EQ(2, hm.size());
//    ASSERT_EQ(2, hm.bucketCount());
//    ASSERT_FALSE(hm.remove("Eric'sDad"));
// }

// TEST(SMALLHashMapTests,  bucketCountIsRightAfterReHash)
// {
//    HashMap hm;
//    hm.add("Arian", "AA");
//    hm.add("Eric", "Cartman");
//    hm.add("Kenny", "Something");
//    hm.add("Kyle", "Bravloski");
//    hm.add("Stan", "Marsh");
//    hm.add("WHoKnows", "Mysterion");
//    hm.add("Buttesr", "Stoch");
//    hm.add("Randy", "Lorde");
//    hm.add("Ariana", "Grande");
//    hm.add("Enriquo", "Cartemenez");
//    ASSERT_EQ(6,hm.bucketCount());
   
// }