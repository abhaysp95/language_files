#ifndef CUBE_H
#define CUBE_H

namespace uiuc {
	class Cube {
		private:
			unsigned length_;
		public:
			Cube();
			Cube(unsigned l);
			void setLength(const unsigned l);
			int getLength();
			void getVolume();
			void getVolume(const unsigned l);
	};
};

#endif
