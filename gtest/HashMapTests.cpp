// HashMapTests.cpp
//
// ICS 45C Spring 2020
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided a few tests
// already, though I've commented them out, because they won't compile and
// link until you've implemented some things.
//
// Of course, you'll want to write lots more of these tests yourself, because
// this is an inexpensive way to know whether things are working the way
// you expect -- including scenarios that you won't happen to hit in the
// course of testing your overall program.  (You might also want to be sure
// that your HashMap implementation is complete and correct before you try
// to write the rest of the program around it, anyway; there's a very
// substantial amount of partial credit available if all that works is
// HashMap.)

#include <gtest/gtest.h>
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


TEST(HashMapTests, containKeyAfterAddingIt)
{
   HashMap hm;
   hm.add("Boo", "perfect");
   hm.add("arian", "here");
   hm.add("was", "123");
   ASSERT_TRUE(hm.contains("Boo"));
   ASSERT_TRUE(hm.contains("arian"));
   ASSERT_TRUE(hm.contains("was"));
   ASSERT_FALSE(hm.contains("NON_EXISTENT_KEY"));
   ASSERT_EQ(3,hm.size());
   

   hm.add("Bool", "trues");
   hm.add("dj", "khaled");
   hm.add("daft", "punk");
   ASSERT_TRUE(hm.contains("Bool"));
   ASSERT_TRUE(hm.contains("dj"));
   ASSERT_TRUE(hm.contains("daft"));
   ASSERT_EQ("trues", hm.value("Bool"));
   ASSERT_EQ("khaled", hm.value("dj"));
   ASSERT_EQ("punk", hm.value("daft"));
   ASSERT_EQ("", hm.value("NON_EXISTENT_KEY2"));
   ASSERT_EQ(6,hm.size());
   hm.remove("Boo");
   ASSERT_FALSE(hm.remove("asdf"));
   
   ASSERT_FALSE(hm.contains("Boo"));
   ASSERT_EQ(5,hm.size());
   hm.remove("dj");
   ASSERT_TRUE(hm.contains("Bool"));
   ASSERT_EQ(4,hm.size());

}

// TEST(HashMapTests, TestCopyCons)
// {
//     HashMap hm;
//     hm.add("arian", "Here");
//     hm.add("gar", "345");
//     hm.add("terry", "678");

//     HashMap hm2 = hm1;
//     ASSERT_EQ(3, hm2.size());
//     ASSERT_TRUE(hm2.contains("arian"));
//     ASSERT_TRUE(hm2.contains("gar"));
//     ASSERT_TRUE(hm2.contains("terry"));
    
// }


// TEST(HashMapTests,  TestAssignmentCopy)
// {
//     HashMap hm, hm2;
//     hm.add("arian", "123");
//     hm.add("gar", "345");
//     hm.add("terry", "678");

//     hm2 = hm;
//     ASSERT_EQ(3, hm2.size());
//     ASSERT_TRUE(hm2.contains("arian"));
//     ASSERT_TRUE(hm2.contains("gar"));
//     ASSERT_TRUE(hm2.contains("terry"));

// }

