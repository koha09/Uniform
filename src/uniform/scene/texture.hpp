#include <uniform/platform/platform.hpp>
#include <uniform/core/size2.hpp>

#ifndef TEXUTRE_HPP
#define TEXUTRE_HPP

class UNIFORM_API Texture
{
public:

	enum class Buffer : size_t {
		texture_1 = 0,
		texture_2,
		texture_3,
		texture_4,
		texture_5,
		texture_6,
		texture_7,
		texture_8,
		texture_9,
		texture_10,
		texture_11,
		texture_12,
		texture_13,
		texture_14,
		texture_15,
		texture_16,
		texture_17,
		texture_18,
		texture_19,
		texture_20,
		texture_21,
		texture_22,
		texture_23,
		texture_24,
		texture_25,
		texture_26,
		texture_27,
		texture_28,
		texture_29,
		texture_30,
		texture_31,
		texture_32
	};

	Texture(const char *file);
	~Texture();

	Size2i get_size();

	void bind(Buffer buffer) const;
	void unbind() const;

private:

    int _bpp = 0;
	uint32_t _id = 0;
	Size2i _size;

};

#endif