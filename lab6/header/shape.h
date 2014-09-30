#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>

namespace shapelab {
	template <class T>
	class Shape {
		public:
			Shape();
			virtual ~Shape();
			void draw();
			void printName();

		protected:
			virtual void drawImpl();
			virtual T area();
			virtual std::string name();
		
		private:
			static int shape_id;
	};
}

#include "shapeImpl.hpp"
#endif // SHAPE_H_

