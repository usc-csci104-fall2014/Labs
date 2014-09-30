#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "shape.h"

namespace shapelab {
	template <class T>
	class Triangle : private Shape<T> {
		public:
			Triangle(T h, T w);
			virtual ~Triangle();
			void printName();

		protected:
			virtual void drawImpl();
			virtual std::string name();

		private:
			T _height;
			T _width;
	};
}

#include "triangleImpl.hpp"
#endif // TRIANGLE_H_

