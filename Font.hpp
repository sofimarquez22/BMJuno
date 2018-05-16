//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
#ifndef SFML_FONT_HPP
#define SFML_FONT_HPP
// Headers
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Glyph.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>
#include <map>
#include <string>
#include <vector>

namespace sf
{
    class InputStream;
    
    class SFML_GRAPHICS_API Font
    {
        public :
        
             Font();
        
             Font(const Font& copy);
        
             ~Font();
        
             bool loadFromFile(const std::string& filename);
        
             bool loadFromMemory(const void* data, std::size_t sizeInBytes);
        
             bool loadFromStream(InputStream& stream);
        
             const Glyph& getGlyph(Uint32 codePoint, unsigned int characterSize, bool bold) const;
        
             int getKerning(Uint32 first, Uint32 second, unsigned int characterSize) const;
        
             int getLineSpacing(unsigned int characterSize) const;
        
             const Texture& getTexture(unsigned int characterSize) const;
        
             Font& operator =(const Font& right);
        
         private :
        
             struct Row
             {
                     Row(unsigned int rowTop, unsigned int rowHeight) : width(0), top(rowTop), height(rowHeight) {}
            
                     unsigned int width;
                     unsigned int top;
                     unsigned int height;
                 };
        
             // Types
             typedef std::map<Uint32, Glyph> GlyphTable;
        
             struct Page
             {
                     Page();
            
                     GlyphTable       glyphs;
                     sf::Texture      texture;
                     unsigned int     nextRow;
                     std::vector<Row> rows;
                 };
        
             void cleanup();
        
             Glyph loadGlyph(Uint32 codePoint, unsigned int characterSize, bool bold) const;
        
             IntRect findGlyphRect(Page& page, unsigned int width, unsigned int height) const;
        
             bool setCurrentSize(unsigned int characterSize) const;
        
             // Types
             typedef std::map<unsigned int, Page> PageTable;
        
             // Member data
             void*                      m_library;
             void*                      m_face;
             void*                      m_streamRec;
             int*                       m_refCount;
             mutable PageTable          m_pages;
             mutable std::vector<Uint8> m_pixelBuffer;
         };
    
     } // namespace sf


 #endif // SFML_FONT_HPP


