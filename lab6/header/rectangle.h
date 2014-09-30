#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"

namespace shapelab {
	template <class T>
	class Rectangle : public Shape<T> {
		public:
			Rectangle(T h, T w);
			virtual ~Rectangle();
			void printName();

		protected:
			virtual void drawImpl();
			virtual T area();
			virtual std::string name();

		private:
			T _height;
			T _width;
	};
}

#include "rectangleImpl.hpp"
#endif // RECTANGLE_H_

