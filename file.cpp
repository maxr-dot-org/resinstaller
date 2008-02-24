/***************************************************************************
 *              Resinstaller - installs missing GFX for MAXR               *
 *              This file is part of the resinstaller project              *
 *   Copyright (C) 2007, 2008 Eiko Oltmanns                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <iostream>
#include <string>
#include <SDL.h>
#include "resinstaller.h"
#include "converter.h"


//first tries to open a file with lowercase name
//if this fails, tries to open the file with uppercase name
SDL_RWops* openFile( string path, const char* mode)
{
	//split string into path and filename
	int pos = (int) path.rfind(PATH_DELIMITER);
	string fileName = path.substr( pos + 1, path.length() );
	path = path.substr( 0, pos + 1 );
	
	//try to open with lower case file name
	int lenght = (int) fileName.size();
	for(int i=0; i < lenght; i++)
	{
		fileName[i] = tolower(fileName[i]); 
	}
	string lowerCaseFileName = fileName;
	SDL_RWops* file = SDL_RWFromFile( (path + fileName).c_str(), mode );
	if ( file != NULL )
	{
		return file;
	}

	//try to open with upper case file name
	for(int i=0; i < lenght; i++)
	{
		fileName[i] = toupper(fileName[i]); 
	}
	file = SDL_RWFromFile( (path + fileName).c_str(), mode );
	if ( file != NULL )
	{
		return file;
	}
	
	throw InstallException( "Couldn't open file '" + path + fileName + "' or '" + lowerCaseFileName + "'" + TEXT_FILE_LF);
	return NULL;
}

void copyFile( string source, string dest )
{
	long int size;
	unsigned char* buffer;
	SDL_RWops *sourceFile = NULL;
	SDL_RWops *destFile = NULL;
	
	try
	{
		sourceFile = openFile ( source, "rb" );
		

		destFile = SDL_RWFromFile ( dest.c_str(), "wb" );
		if ( destFile == NULL )
		{
			throw InstallException (string( "Couldn't open file for writing") + TEXT_FILE_LF );
		}

		SDL_RWseek( sourceFile, 0, SEEK_END );
		size = SDL_RWtell( sourceFile );

		buffer = (unsigned char*) malloc( size );
		if ( buffer == NULL )
		{
			cout << "Out of memory\n";
			exit (-1);
		}

		SDL_RWseek( sourceFile, 0, SEEK_SET);
		SDL_RWread( sourceFile, buffer, 1, size );

		SDL_RWwrite( destFile, buffer, 1, size );

		free ( buffer );
	}
	END_INSTALL_FILE( dest );

	if (sourceFile) SDL_RWclose( sourceFile );
	if (destFile)   SDL_RWclose( destFile );

}
