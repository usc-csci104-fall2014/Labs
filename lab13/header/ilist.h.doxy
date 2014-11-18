#ifndef ILIST_H
#define ILIST_H

/** \brief
 *  IList is a template abstract class for all list-like classes
 *
 * The IList is an abstract class that all other list-like classes
 * have to inherit from. This enforces enough public member functions
 * therefore speed testing is easier. We will also practice polymorphism with this nice interface.
 */
template <class T>
class IList
{
  public:

	///
	/// virtual destructor for all child classes
	/// \todo check if all other classes have virtual destructor
	///
    virtual ~IList () {}

    ///
    /// returns the number of elements in the list
    ///
    virtual int size () const = 0;

    /** \brief Inserts a new item at the given position

       Inserts _val_ into the list before the given position,
       shifting all later items one position to the right.
       Inserting before 0 (i.e., position = 0) makes it the
       new first element.
       Inserting before size() (i.e., position = size()) makes
       it the new last element.
       Your function should throw an exception if position is
       outside the legal range, which would be 0-size() here.

       @param[in] val the new item passed by constant reference
       @param[in] position location to insert the new value

       Assuming size is 5, here is what will happen:

       |position  |behavior            |
       |:---------:|:-------------------|
       |-1  |exception            |
       |0  |insert at head            |
       |1  |insert in the middle            |
       |5  |insert at the end            |
       |6  |exception            |
    */
    virtual void insert (int position, const T & val) = 0;

    /** \brief Removes one item from the given position.

       Removes the item from the given position, shifting all
       later items one position to the left.
       Your function should throw an exception if position is
       outside the legal range, which is 0-(size()-1) here.

       @param[in] position location to remove from
    */
    virtual void remove (int position) = 0;

    /** \brief Sets the item at the given position with a new value
        \bug sample text to explain a bug in remove function

       Overwrites the given position with the given value.
       Does not affect any other positions.
       Your function should throw an exception if position is
       outside the legal range, which is 0-(size()-1) here.

       @param[in] val the new item passed by constant reference
       @param[in] position location to set the new value
     */
    virtual void set (int position, const T & val) = 0;

    /** \brief Returns the item at the given position **byref**
        \warning Be careful as you can modify the value inside

       Returns the item at the given position.
       Your function should throw an exception if position is
       outside the legal range.

       @param[in] position location to get item from
       @return value of item by reference (**changeable**)
    */
    virtual T& get (int position) = 0;

    /** \brief Returns the item at the given position as constant byref
        \note This is return by constant reference so you need to create a copy if you intent to work with the output in your own code.

       Returns the item at the given position.
       Your function should throw an exception if position is
       outside the legal range

       @param[in] position location to get item from
       @return value of item by constant reference
    */
    virtual T const & get (int position) const = 0 ;
};
#endif

