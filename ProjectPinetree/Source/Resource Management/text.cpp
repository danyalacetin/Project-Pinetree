// This include:
#include "text.h"

// Local includes:
#include "texture.h"

// Library includes:
#include <sstream>
#include <cassert>

Text::Text(Texture* pTexture)
: m_textAlignment(ALIGN_CENTRE)
{
	assert(pTexture);

	m_pTexture = pTexture;
	m_iHeight = pTexture->GetHeight();
	m_iWidth = pTexture->GetWidth();
}

Text::~Text()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

int Text::GetWidth() const
{
	return m_iWidth;
}

int Text::GetHeight() const
{
	return m_iHeight;
}

void Text::SetAlignment(TextAlignment newAlignment)
{
	m_textAlignment = newAlignment;
}

TextAlignment Text::GetAlignment() const
{
	return m_textAlignment;
}

Texture & Text::GetTexture() const
{
	return *m_pTexture;
}

void TextDef::SetColour(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
	alpha = 255;
}

std::string TextDef::toString()
{
	std::ostringstream sstream;

	sstream << size << "-";
	sstream << alpha << "-";
	sstream << red << "-";
	sstream << green << "-";
	sstream << blue;

	return sstream.str();
}
