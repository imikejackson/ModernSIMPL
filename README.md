# Design Notes #

In the original coding of SIMPL circa 2009~2011 some of the over all design cues were taken from several large projects such as VTK/ParaView/ITK. While this design has served the project well since then several C++ specifications (C++11, C++14 and C++17) have been released which improve the C++ language in several ways and bring the syntax up-to-date with missing features. Now that all major developers of DREAM.3D/SIMPL are on a compatible compiler suite the developers have started looking at ways of updating/rewriting SIMPL to bring it up to "modern" C++ philosophies and design styles.

To this end the developers have been working with outside developers with extensive modern C++ coding experience. This small version of just the __DataContainerArray__, __DataContainer__, __AttributeMatrix__, and __IDataArray__ heirarchy uses the follwoing design ideas:

+ The Model-View-Controller design pattern
+ _Heavy_ data is stored in a *Model class
+ _Index_ classes are used to access the various levels of the heirarchy.
+ Shared Pointers (std::shared_ptr<>) are not used in this design.
+ Modern C++ syntax is embraced in this design instead of over using the std::shared_ptr<> of the current design.
+ Heavy use of std::shared_ptr<> in the current code base creates subtle bugs that are hard to diagnose
+ Heavy use of std::shared_ptr<> also leads to very long compile times due to inclusion of headers instead of forward declaration
+ This design borrows from the QAbstractModel and QItemIdex design patterns.
