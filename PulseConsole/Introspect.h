/***
 This file is part of PulseConsole
 
 Copyright 2010,2011 Daniel Mack <pulseaudio@zonque.de>
 
 PulseConsole is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 PulseConsole is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with PulseAudio; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 USA.
 ***/

#import <Cocoa/Cocoa.h>

@interface Introspect : NSObject <NSTableViewDelegate, NSTableViewDataSource>
{
	IBOutlet NSTableView	*selectionTableView;
	IBOutlet NSTableView	*parameterTableView;
	IBOutlet NSTableView	*propertyTableView;
	IBOutlet NSButton	*activeButton;

	NSMutableArray *outlineToplevel;
	NSMutableDictionary *parameters;
	NSMutableDictionary *properties;
	PAServerConnection *connection;
}

@property (nonatomic, retain) PAServerConnection *connection;

- (void) serverReady;
- (void) invalidateAll;
- (void) contentChanged: (PAElementInfo *) item;
- (void) enableGUI: (BOOL) enabled;
- (void) repaintViews;

@end
