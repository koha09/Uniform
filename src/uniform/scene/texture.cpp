#include <uniform/scene/texture.hpp>

#include <glad/glad.h>
#include <stb_image.h>

Texture::Texture(const std::string& file) {
	stbi_set_flip_vertically_on_load(true);
	uint8_t* image = stbi_load(file.c_str(), &_size.x, &_size.y, &_bpp, 4);
	if (image) {
        glGenTextures(1, &_id);
		glBindTexture(GL_TEXTURE_2D, _id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _size.x, _size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(image);
	} else {
		throw UF_EXCEPTION_NOT_FOUND;
	}
}

Texture::~Texture() {
	glDeleteTextures(1, &_id);
}

Size2i Texture::get_size() {
	return _size;
}

void Texture::bind(Buffer buffer) const {
    glActiveTexture(GL_TEXTURE0 + (uint32_t)buffer);
	glBindTexture(GL_TEXTURE_2D, _id);
}

void Texture::unbind() const {
	glBindTexture(GL_TEXTURE_2D, 0);
}