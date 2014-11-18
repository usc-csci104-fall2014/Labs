#ifndef ILIST_H
#define ILIST_H

template <class T>
class IList
{
  public:

    virtual ~IList () {}

    virtual int size () const = 0;

    virtual void insert (int position, const T & val) = 0;

    virtual void remove (int position) = 0;

    virtual void set (int position, const T & val) = 0;

    virtual T& get (int position) = 0;

    virtual T const & get (int position) const = 0 ;
};
#endif
