{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 730.0, 153.0, 343.0, 325.0 ],
		"bglocked" : 0,
		"defrect" : [ 730.0, 153.0, 343.0, 325.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 14.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 20.0, 20.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 0,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print",
					"patching_rect" : [ 85.0, 285.0, 38.0, 23.0 ],
					"id" : "obj-2",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 14.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "dump 4",
					"patching_rect" : [ 105.0, 165.0, 57.0, 21.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-4",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 14.0,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t 4",
					"patching_rect" : [ 185.0, 165.0, 26.0, 23.0 ],
					"outlettype" : [ "int" ],
					"id" : "obj-5",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 14.0,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"patching_rect" : [ 185.0, 85.0, 20.0, 20.0 ],
					"outlettype" : [ "int" ],
					"id" : "obj-35",
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "metro 250",
					"patching_rect" : [ 185.0, 125.0, 74.0, 23.0 ],
					"outlettype" : [ "bang" ],
					"id" : "obj-33",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 14.0,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Galois Lattice // 100",
					"frgb" : [ 0.93, 0.93, 0.97, 1.0 ],
					"patching_rect" : [ 13.0, 42.0, 235.0, 23.0 ],
					"textcolor" : [ 0.93, 0.93, 0.97, 1.0 ],
					"id" : "obj-12",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 14.0,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Romeo",
					"frgb" : [ 0.93, 0.93, 0.97, 1.0 ],
					"patching_rect" : [ 13.0, 12.0, 107.0, 30.0 ],
					"textcolor" : [ 0.93, 0.93, 0.97, 1.0 ],
					"id" : "obj-14",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontface" : 3,
					"fontsize" : 20.871338,
					"numoutlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p MIDI",
					"patching_rect" : [ 25.0, 285.0, 52.0, 23.0 ],
					"id" : "obj-22",
					"fontname" : "Arial",
					"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
					"numinlets" : 1,
					"fontsize" : 14.0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 417.0, 141.0, 368.0, 385.0 ],
						"bglocked" : 0,
						"defrect" : [ 417.0, 141.0, 368.0, 385.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 20.0, 20.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p",
									"patching_rect" : [ 20.0, 60.0, 32.0, 23.0 ],
									"outlettype" : [ "" ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
									"numinlets" : 1,
									"fontsize" : 14.0,
									"numoutlets" : 1,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 364.0, 91.0, 336.0, 149.0 ],
										"bglocked" : 0,
										"defrect" : [ 364.0, 91.0, 336.0, 149.0 ],
										"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
										"openinpresentation" : 0,
										"default_fontsize" : 14.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 0,
										"gridsize" : [ 20.0, 20.0 ],
										"gridsnaponopen" : 0,
										"toolbarvisible" : 1,
										"boxanimatetime" : 200,
										"imprint" : 0,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"boxes" : [ 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "vexpr $i1*(random (0\\,7) != 0) @scalarmode 1",
													"patching_rect" : [ 20.0, 60.0, 296.0, 23.0 ],
													"outlettype" : [ "" ],
													"id" : "obj-3",
													"fontname" : "Arial",
													"numinlets" : 1,
													"fontsize" : 14.0,
													"numoutlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"patching_rect" : [ 20.0, 100.0, 25.0, 25.0 ],
													"id" : "obj-2",
													"numinlets" : 1,
													"numoutlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
													"outlettype" : [ "list" ],
													"id" : "obj-1",
													"numinlets" : 0,
													"numoutlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"default_fontface" : 0,
										"fontname" : "Arial",
										"default_fontname" : "Arial",
										"globalpatchername" : "",
										"default_fontsize" : 14.0,
										"fontface" : 0,
										"fontsize" : 14.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "freebang",
									"patching_rect" : [ 300.0, 40.0, 66.0, 23.0 ],
									"outlettype" : [ "bang" ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 0,
									"fontsize" : 14.0,
									"numoutlets" : 1,
									"hidden" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "i 0",
									"patching_rect" : [ 300.0, 120.0, 36.0, 23.0 ],
									"outlettype" : [ "int" ],
									"id" : "obj-18",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 14.0,
									"numoutlets" : 1,
									"hidden" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "uzi 16 1",
									"patching_rect" : [ 300.0, 80.0, 72.0, 23.0 ],
									"outlettype" : [ "bang", "bang", "int" ],
									"id" : "obj-17",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 14.0,
									"numoutlets" : 3,
									"hidden" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "ctlout 123",
									"patching_rect" : [ 300.0, 160.0, 72.0, 23.0 ],
									"id" : "obj-19",
									"fontname" : "Arial",
									"numinlets" : 3,
									"fontsize" : 14.0,
									"numoutlets" : 0,
									"hidden" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadmess 26",
									"patching_rect" : [ 240.0, 280.0, 90.0, 23.0 ],
									"outlettype" : [ "" ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 14.0,
									"numoutlets" : 1,
									"hidden" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p Y",
									"patching_rect" : [ 200.0, 280.0, 31.0, 23.0 ],
									"outlettype" : [ "" ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
									"numinlets" : 1,
									"fontsize" : 14.0,
									"numoutlets" : 1,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 495.0, 187.0, 132.0, 419.0 ],
										"bglocked" : 0,
										"defrect" : [ 495.0, 187.0, 132.0, 419.0 ],
										"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
										"openinpresentation" : 0,
										"default_fontsize" : 14.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 0,
										"gridsize" : [ 20.0, 20.0 ],
										"gridsnaponopen" : 0,
										"toolbarvisible" : 1,
										"boxanimatetime" : 200,
										"imprint" : 0,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"boxes" : [ 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "+ 1",
													"patching_rect" : [ 20.0, 60.0, 32.5, 23.0 ],
													"outlettype" : [ "int" ],
													"id" : "obj-9",
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"patching_rect" : [ 20.0, 360.0, 25.0, 25.0 ],
													"id" : "obj-7",
													"numinlets" : 1,
													"numoutlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pack",
													"patching_rect" : [ 20.0, 320.0, 40.0, 23.0 ],
													"outlettype" : [ "" ],
													"id" : "obj-6",
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b i",
													"patching_rect" : [ 20.0, 220.0, 40.0, 23.0 ],
													"outlettype" : [ "bang", "int" ],
													"id" : "obj-5",
													"fontname" : "Arial",
													"numinlets" : 1,
													"fontsize" : 14.0,
													"numoutlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 16",
													"patching_rect" : [ 20.0, 140.0, 48.0, 23.0 ],
													"outlettype" : [ "bang", "bang", "int" ],
													"id" : "obj-4",
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "int",
													"patching_rect" : [ 60.0, 280.0, 32.5, 23.0 ],
													"outlettype" : [ "int" ],
													"id" : "obj-3",
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b i",
													"patching_rect" : [ 20.0, 100.0, 73.0, 23.0 ],
													"outlettype" : [ "bang", "int" ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 1,
													"fontsize" : 14.0,
													"numoutlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
													"outlettype" : [ "int" ],
													"id" : "obj-1",
													"numinlets" : 0,
													"numoutlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-9", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-9", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-7", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-6", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-5", 1 ],
													"destination" : [ "obj-6", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 1 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-4", 2 ],
													"destination" : [ "obj-5", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-4", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"default_fontface" : 0,
										"fontname" : "Arial",
										"default_fontname" : "Arial",
										"globalpatchername" : "",
										"default_fontsize" : 14.0,
										"fontface" : 0,
										"fontsize" : 14.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "umenu",
									"patching_rect" : [ 200.0, 220.0, 151.0, 25.0 ],
									"framecolor" : [ 0.827451, 0.827451, 0.827451, 0.0 ],
									"outlettype" : [ "int", "", "" ],
									"arrow" : 0,
									"id" : "obj-6",
									"fontname" : "Arial",
									"align" : 1,
									"hltcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"bgcolor" : [ 0.827451, 0.737255, 0.835294, 0.0 ],
									"arrowframe" : 0,
									"textcolor2" : [ 0.0, 0.0, 0.0, 1.0 ],
									"numinlets" : 1,
									"fontsize" : 16.0,
									"numoutlets" : 3,
									"items" : [ "Grand", "Piano", ",", "Bright", "Piano", ",", "Electric", "Grand", ",", "Honkytonk", "Piano", ",", "Electric", "Piano", 1, ",", "Electric", "Piano", 2, ",", "Harpsichord", ",", "Clavinet", ",", "Celesta", ",", "Glockenspiel", ",", "Music", "Box", ",", "Vibraphone", ",", "Marimba", ",", "Xylophone", ",", "Tubular", "Bell", ",", "Dulcimer", ",", "Drawbar", "Organ", ",", "Percussive", "Organ", ",", "Rock", "Organ", ",", "Church", "Organ", ",", "Reed", "Organ", ",", "Accordion", ",", "Harmonica", ",", "Tango", "Accordion", ",", "Nylon", "String", "Guitar", ",", "Steel", "String", "Guitar", ",", "Jazz", "Guitar", ",", "Clean", "Guitar", ",", "Muted", "Guitar", ",", "Overdrive", "Guitar", ",", "Distortion", "Guitar", ",", "Guitar", "Harmonics", ",", "Acoustic", "Bass", ",", "Fingered", "Bass", ",", "Picked", "Bass", ",", "Fretless", "Bass", ",", "Slap", "Bass", 1, ",", "Slap", "Bass", 2, ",", "Synth", "Bass", 1, ",", "Synth", "Bass", 2, ",", "Violin", ",", "Viola", ",", "Cello", ",", "Contrabass", ",", "Tremolo", "Strings", ",", "Pizzicato", "Strings", ",", "Harp", ",", "Timpani", ",", "String", "Ensemble", ",", "Slow", "Strings", ",", "Synth", "Strings", 1, ",", "Synth", "Strings", 2, ",", "Choir", "Aahs", ",", "Voice", "Oohs", ",", "Synth", "Vox", ",", "Orchestra", "Hit", ",", "Trumpet", ",", "Trombone", ",", "Tuba", ",", "Muted", "Trumpet", ",", "French", "Horn", ",", "Brass", 1, ",", "Synth", "Brass", 1, ",", "Synth", "Brass", 2, ",", "Soprano", "Sax", ",", "Alto", "Sax", ",", "Tenor", "Sax", ",", "Baritone", "Sax", ",", "Oboe", ",", "English", "Horn", ",", "Bassoon", ",", "Clarinet", ",", "Piccolo", ",", "Flute", ",", "Recorder", ",", "Pan", "Flute", ",", "Blown", "Bottle", ",", "Shakuhachi", ",", "Whistle", ",", "Ocarina", ",", "Square", "Wave", ",", "Sawtooth", "Wave", ",", "Synth", "Calliope", ",", "Chiffer", "Lead", ",", "Charang", ",", "Solo", "Vox", ",", "5th", "Sawtooth", "Wave", ",", "Bass", "and", "Lead", ",", "Fantasia", ",", "Warm", "Pad", ",", "Polysynth", ",", "Space", "Voice", ",", "Bowed", "Glass", ",", "Metal", "Pad", ",", "Halo", "Pad", ",", "Sweep", "Pad", ",", "Ice", "Rain", ",", "Soundtrack", ",", "Crystal", ",", "Atmosphere", ",", "Brightness", ",", "Goblin", ",", "Echo", "Drops", ",", "Star", "Theme", ",", "Sitar", ",", "Banjo", ",", "Shamisen", ",", "Koto", ",", "Kalimba", ",", "Bag", "Pipe", ",", "Fiddle", ",", "Shanai", ",", "Tinkle", "Bell", ",", "Agogo", ",", "Steel", "Drums", ",", "Woodblock", ",", "Taiko", ",", "Melo", "Tom", ",", "Synth", "Drum", ",", "Reverse", "Cymbal", ",", "Guitar", "Fret", "Noise", ",", "Breath", "Noise", ",", "Seashore", ",", "Bird", ",", "Telephone", ",", "Helicopter", ",", "Applause", ",", "Gun", "Shot" ],
									"bgcolor2" : [ 0.917647, 0.937255, 0.670588, 1.0 ],
									"types" : [  ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pgmout",
									"patching_rect" : [ 200.0, 340.0, 57.0, 23.0 ],
									"id" : "obj-368",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 14.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p",
									"patching_rect" : [ 20.0, 260.0, 32.0, 23.0 ],
									"outlettype" : [ "" ],
									"id" : "obj-16",
									"fontname" : "Arial",
									"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
									"numinlets" : 1,
									"fontsize" : 14.0,
									"numoutlets" : 1,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 614.0, 149.0, 241.0, 309.0 ],
										"bglocked" : 0,
										"defrect" : [ 614.0, 149.0, 241.0, 309.0 ],
										"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
										"openinpresentation" : 0,
										"default_fontsize" : 14.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 0,
										"gridsize" : [ 20.0, 20.0 ],
										"gridsnaponopen" : 0,
										"toolbarvisible" : 1,
										"boxanimatetime" : 200,
										"imprint" : 0,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"boxes" : [ 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sel 0",
													"patching_rect" : [ 20.0, 60.0, 40.0, 23.0 ],
													"outlettype" : [ "bang", "" ],
													"id" : "obj-4",
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "p",
													"patching_rect" : [ 180.0, 160.0, 34.0, 23.0 ],
													"outlettype" : [ "float" ],
													"id" : "obj-38",
													"fontname" : "Arial",
													"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
													"numinlets" : 1,
													"fontsize" : 14.0,
													"numoutlets" : 1,
													"patcher" : 													{
														"fileversion" : 1,
														"appversion" : 														{
															"major" : 5,
															"minor" : 1,
															"revision" : 9
														}
,
														"rect" : [ 50.0, 180.0, 109.0, 266.0 ],
														"bglocked" : 0,
														"defrect" : [ 50.0, 180.0, 109.0, 266.0 ],
														"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
														"openinpresentation" : 0,
														"default_fontsize" : 14.0,
														"default_fontface" : 0,
														"default_fontname" : "Arial",
														"gridonopen" : 0,
														"gridsize" : [ 20.0, 20.0 ],
														"gridsnaponopen" : 0,
														"toolbarvisible" : 1,
														"boxanimatetime" : 200,
														"imprint" : 0,
														"enablehscroll" : 1,
														"enablevscroll" : 1,
														"devicewidth" : 0.0,
														"boxes" : [ 															{
																"box" : 																{
																	"maxclass" : "newobj",
																	"text" : "* 1000.",
																	"patching_rect" : [ 20.0, 180.0, 55.0, 23.0 ],
																	"outlettype" : [ "float" ],
																	"id" : "obj-27",
																	"fontname" : "Arial",
																	"numinlets" : 2,
																	"fontsize" : 14.0,
																	"numoutlets" : 1
																}

															}
, 															{
																"box" : 																{
																	"maxclass" : "newobj",
																	"text" : "!- 1.",
																	"patching_rect" : [ 20.0, 100.0, 35.0, 23.0 ],
																	"outlettype" : [ "float" ],
																	"id" : "obj-26",
																	"fontname" : "Arial",
																	"numinlets" : 2,
																	"fontsize" : 14.0,
																	"numoutlets" : 1
																}

															}
, 															{
																"box" : 																{
																	"maxclass" : "newobj",
																	"text" : "pow 2",
																	"patching_rect" : [ 20.0, 140.0, 48.0, 23.0 ],
																	"outlettype" : [ "float" ],
																	"id" : "obj-21",
																	"fontname" : "Arial",
																	"numinlets" : 2,
																	"fontsize" : 14.0,
																	"numoutlets" : 1
																}

															}
, 															{
																"box" : 																{
																	"maxclass" : "newobj",
																	"text" : "/ 127.",
																	"patching_rect" : [ 20.0, 60.0, 46.0, 23.0 ],
																	"outlettype" : [ "float" ],
																	"id" : "obj-7",
																	"fontname" : "Arial",
																	"numinlets" : 2,
																	"fontsize" : 14.0,
																	"numoutlets" : 1
																}

															}
, 															{
																"box" : 																{
																	"maxclass" : "inlet",
																	"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
																	"outlettype" : [ "int" ],
																	"id" : "obj-35",
																	"numinlets" : 0,
																	"numoutlets" : 1,
																	"comment" : ""
																}

															}
, 															{
																"box" : 																{
																	"maxclass" : "outlet",
																	"patching_rect" : [ 20.0, 220.0, 25.0, 25.0 ],
																	"id" : "obj-37",
																	"numinlets" : 1,
																	"numoutlets" : 0,
																	"comment" : ""
																}

															}
 ],
														"lines" : [ 															{
																"patchline" : 																{
																	"source" : [ "obj-27", 0 ],
																	"destination" : [ "obj-37", 0 ],
																	"hidden" : 0,
																	"midpoints" : [  ]
																}

															}
, 															{
																"patchline" : 																{
																	"source" : [ "obj-21", 0 ],
																	"destination" : [ "obj-27", 0 ],
																	"hidden" : 0,
																	"midpoints" : [  ]
																}

															}
, 															{
																"patchline" : 																{
																	"source" : [ "obj-7", 0 ],
																	"destination" : [ "obj-26", 0 ],
																	"hidden" : 0,
																	"midpoints" : [  ]
																}

															}
, 															{
																"patchline" : 																{
																	"source" : [ "obj-35", 0 ],
																	"destination" : [ "obj-7", 0 ],
																	"hidden" : 0,
																	"midpoints" : [  ]
																}

															}
, 															{
																"patchline" : 																{
																	"source" : [ "obj-26", 0 ],
																	"destination" : [ "obj-21", 0 ],
																	"hidden" : 0,
																	"midpoints" : [  ]
																}

															}
 ]
													}
,
													"saved_object_attributes" : 													{
														"default_fontface" : 0,
														"fontname" : "Arial",
														"default_fontname" : "Arial",
														"globalpatchername" : "",
														"default_fontsize" : 14.0,
														"fontface" : 0,
														"fontsize" : 14.0
													}

												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "+ 30",
													"patching_rect" : [ 80.0, 180.0, 38.0, 23.0 ],
													"outlettype" : [ "int" ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "random 40",
													"patching_rect" : [ 80.0, 140.0, 77.0, 23.0 ],
													"outlettype" : [ "int" ],
													"id" : "obj-3",
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pack 0 0 0",
													"patching_rect" : [ 20.0, 220.0, 138.0, 23.0 ],
													"outlettype" : [ "" ],
													"id" : "obj-5",
													"fontname" : "Arial",
													"numinlets" : 3,
													"fontsize" : 14.0,
													"numoutlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t i b i",
													"patching_rect" : [ 20.0, 100.0, 139.0, 23.0 ],
													"outlettype" : [ "int", "bang", "int" ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 1,
													"fontsize" : 14.0,
													"numoutlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
													"outlettype" : [ "int" ],
													"id" : "obj-14",
													"numinlets" : 0,
													"numoutlets" : 1,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"patching_rect" : [ 20.0, 260.0, 25.0, 25.0 ],
													"id" : "obj-15",
													"numinlets" : 1,
													"numoutlets" : 0,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 1 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-4", 1 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-14", 0 ],
													"destination" : [ "obj-4", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-38", 0 ],
													"destination" : [ "obj-5", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 2 ],
													"destination" : [ "obj-38", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-5", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-5", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-15", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"default_fontface" : 0,
										"fontname" : "Arial",
										"default_fontname" : "Arial",
										"globalpatchername" : "",
										"default_fontsize" : 14.0,
										"fontface" : 0,
										"fontsize" : 14.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "makenote 90 250 1",
									"patching_rect" : [ 20.0, 300.0, 138.0, 23.0 ],
									"outlettype" : [ "float", "float", "float" ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 4,
									"fontsize" : 14.0,
									"numoutlets" : 3
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pipe 775",
									"patching_rect" : [ 80.0, 160.0, 64.0, 23.0 ],
									"outlettype" : [ "" ],
									"id" : "obj-13",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 14.0,
									"numoutlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pipe 375",
									"patching_rect" : [ 200.0, 160.0, 64.0, 23.0 ],
									"outlettype" : [ "" ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 14.0,
									"numoutlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "unpack 0 0 0 0",
									"patching_rect" : [ 20.0, 120.0, 199.0, 23.0 ],
									"outlettype" : [ "int", "int", "int", "int" ],
									"id" : "obj-9",
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 14.0,
									"numoutlets" : 4
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "noteout",
									"patching_rect" : [ 20.0, 340.0, 138.0, 23.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"color" : [ 0.501961, 0.717647, 0.764706, 1.0 ],
									"numinlets" : 3,
									"fontsize" : 14.0,
									"numoutlets" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
									"outlettype" : [ "list" ],
									"id" : "obj-1",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : "(list)"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 1,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 1,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 1,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-18", 0 ],
									"destination" : [ "obj-19", 0 ],
									"hidden" : 1,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 2 ],
									"destination" : [ "obj-19", 2 ],
									"hidden" : 1,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 1 ],
									"destination" : [ "obj-4", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 2 ],
									"destination" : [ "obj-4", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 3 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 1 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-368", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 2 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [ 149.5, 210.0, 29.5, 210.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [ 209.5, 210.0, 29.5, 210.0 ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"fontname" : "Arial",
						"default_fontname" : "Arial",
						"globalpatchername" : "",
						"default_fontsize" : 14.0,
						"fontface" : 0,
						"fontsize" : 14.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"patching_rect" : [ 25.0, 85.0, 20.0, 20.0 ],
					"outlettype" : [ "bang" ],
					"id" : "obj-21",
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p TUTO41",
					"patching_rect" : [ 25.0, 125.0, 76.0, 23.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-25",
					"fontname" : "Arial",
					"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
					"numinlets" : 1,
					"fontsize" : 14.0,
					"numoutlets" : 1,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 184.0, 54.0, 426.0, 706.0 ],
						"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
						"bglocked" : 0,
						"defrect" : [ 184.0, 54.0, 426.0, 706.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 14.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 20.0, 20.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 1,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "+ 1",
									"patching_rect" : [ 100.0, 560.0, 32.5, 23.0 ],
									"outlettype" : [ "int" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 2,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 1,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 4",
									"patching_rect" : [ 100.0, 520.0, 70.0, 23.0 ],
									"outlettype" : [ "int" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 2,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 1,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t l b",
									"patching_rect" : [ 60.0, 480.0, 43.0, 23.0 ],
									"outlettype" : [ "", "bang" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 1,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 2,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "prepend learn",
									"patching_rect" : [ 60.0, 620.0, 97.0, 23.0 ],
									"outlettype" : [ "" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-12",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 1,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 1,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl group 4",
									"patching_rect" : [ 60.0, 440.0, 72.0, 23.0 ],
									"outlettype" : [ "", "" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-15",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 2,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 2,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "if $i1>=0 then $i1",
									"patching_rect" : [ 80.0, 220.0, 118.0, 23.0 ],
									"outlettype" : [ "" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 1,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 1,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 60.0, 660.0, 25.0, 25.0 ],
									"presentation" : 0,
									"id" : "obj-11",
									"background" : 0,
									"numinlets" : 1,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"ignoreclick" : 0,
									"numoutlets" : 0,
									"hidden" : 0,
									"comment" : "(int)"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "trigger next",
									"patching_rect" : [ 80.0, 340.0, 81.0, 23.0 ],
									"outlettype" : [ "next" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 1,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 1,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"patching_rect" : [ 120.0, 20.0, 68.0, 23.0 ],
									"outlettype" : [ "bang" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-9",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 1,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 1,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t next start",
									"patching_rect" : [ 20.0, 60.0, 76.0, 23.0 ],
									"outlettype" : [ "next", "start" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 1,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 2,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
									"outlettype" : [ "bang" ],
									"presentation" : 0,
									"id" : "obj-2",
									"background" : 0,
									"numinlets" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"ignoreclick" : 0,
									"numoutlets" : 1,
									"hidden" : 0,
									"comment" : "(bang)"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "delay",
									"patching_rect" : [ 80.0, 300.0, 44.0, 23.0 ],
									"outlettype" : [ "bang" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-20",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 2,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 1,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "trigger b i",
									"patching_rect" : [ 80.0, 260.0, 69.0, 23.0 ],
									"outlettype" : [ "bang", "int" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-19",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 1,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 2,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "noteout",
									"patching_rect" : [ 220.0, 260.0, 130.0, 23.0 ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-17",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.501961, 0.717647, 0.764706, 1.0 ],
									"numinlets" : 3,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 0,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "makenote 90 250 1",
									"patching_rect" : [ 220.0, 220.0, 130.0, 23.0 ],
									"outlettype" : [ "float", "float", "float" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-16",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 4,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 3,
									"hidden" : 0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "read tutorial41.mid",
									"patching_rect" : [ 120.0, 60.0, 126.0, 21.0 ],
									"outlettype" : [ "" ],
									"gradient" : 0,
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"bgcolor" : [ 0.866667, 0.866667, 0.866667, 0.0 ],
									"background" : 0,
									"numinlets" : 2,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 1,
									"hidden" : 0,
									"bgcolor2" : [ 0.867, 0.867, 0.867, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "detonate",
									"patching_rect" : [ 20.0, 140.0, 300.5, 23.0 ],
									"outlettype" : [ "int", "int", "int", "int", "int", "int", "int", "int" ],
									"presentation" : 0,
									"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"background" : 0,
									"color" : [ 0.8, 0.84, 0.71, 1.0 ],
									"numinlets" : 8,
									"fontface" : 0,
									"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
									"fontsize" : 14.0,
									"ignoreclick" : 0,
									"numoutlets" : 8,
									"hidden" : 0,
									"save" : [ "#N", "detonate", "", ";", "#X", "setparam", 0, "Time", 0, 0, 999999, 0, 1000, 200, 0, ";", "#X", "setparam", 1, "Pitch", 0, 0, 127, 60, 12, 4, 0, ";", "#X", "setparam", 2, "Vel", 0, 0, 127, 64, 12, 4, 0, ";", "#X", "setparam", 3, "Dur", 0, 1, 99999, 200, 800, 200, 0, ";", "#X", "setparam", 4, "Chan", 0, 1, 16, 1, 8, 1, 0, ";", "#X", "setparam", 5, "Track", 0, 1, 32, 1, 8, 1, 0, ";", "#X", "setparam", 6, "X1", 0, 0, 999, 0, 80, 20, 0, ";", "#X", "setparam", 7, "X2", 0, 0, 999, 0, 80, 20, 0, ";", "#X", "restore", ";", "#X", 0, 40, 54, 994, 4, 1, 0, 0, ";", "#X", 0, 71, 85, 57, 4, 1, 0, 0, ";", "#X", 57, 72, 62, 62, 4, 1, 0, 0, ";", "#X", 62, 47, 55, 10, 4, 1, 0, 0, ";", "#X", 0, 71, 87, 63, 4, 1, 0, 0, ";", "#X", 63, 69, 103, 62, 4, 1, 0, 0, ";", "#X", 62, 52, 63, 10, 4, 1, 0, 0, ";", "#X", 0, 71, 96, 10, 4, 1, 0, 0, ";", "#X", 125, 59, 64, 125, 4, 1, 0, 0, ";", "#X", 125, 64, 64, 10, 4, 1, 0, 0, ";", "#X", 84, 72, 71, 10, 4, 1, 0, 0, ";", "#X", 41, 65, 54, 10, 4, 1, 0, 0, ";", "#X", 42, 74, 77, 83, 4, 1, 0, 0, ";", "#X", 83, 64, 64, 10, 4, 1, 0, 0, ";", "#X", 0, 76, 84, 84, 4, 1, 0, 0, ";", "#X", 84, 74, 70, 10, 4, 1, 0, 0, ";", "#X", 41, 59, 57, 10, 4, 1, 0, 0, ";", "#X", 42, 72, 73, 83, 4, 1, 0, 0, ";", "#X", 83, 62, 70, 500, 4, 1, 0, 0, ";", "#X", 0, 71, 62, 84, 4, 1, 0, 0, ";", "#X", 84, 69, 64, 10, 4, 1, 0, 0, ";", "#X", 41, 38, 57, 10, 4, 1, 0, 0, ";", "#X", 42, 67, 66, 83, 4, 1, 0, 0, ";", "#X", 83, 50, 71, 10, 4, 1, 0, 0, ";", "#X", 0, 69, 96, 10, 4, 1, 0, 0, ";", "#X", 125, 57, 69, 125, 4, 1, 0, 0, ";", "#X", 125, 60, 60, 125, 4, 1, 0, 0, ";", "#X", 84, 71, 62, 83, 4, 1, 0, 0, ";", "#X", 41, 62, 59, 10, 4, 1, 0, 0, ";", "#X", 42, 69, 70, 83, 4, 1, 0, 0, ";", "#X", 83, 60, 60, 125, 4, 1, 0, 0, ";", "#X", 0, 67, 84, 84, 4, 1, 0, 0, ";", "#X", 84, 69, 74, 83, 4, 1, 0, 0, ";", "#X", 41, 59, 75, 10, 4, 1, 0, 0, ";", "#X", 42, 67, 88, 83, 4, 1, 0, 0, ";", "#X", 83, 57, 82, 375, 4, 1, 0, 0, ";", "#X", 0, 65, 66, 63, 4, 1, 0, 0, ";", "#X", 63, 67, 56, 62, 4, 1, 0, 0, ";", "#X", 62, 45, 63, 10, 4, 1, 0, 0, ";", "#X", 0, 65, 67, 63, 4, 1, 0, 0, ";", "#X", 63, 64, 80, 10, 4, 1, 0, 0, ";", "#X", 62, 52, 66, 125, 4, 1, 0, 0, ";", "#X", 125, 71, 63, 125, 4, 1, 0, 0, ";", "#X", 0, 57, 66, 125, 4, 1, 0, 0, ";", "#X", 125, 76, 68, 63, 4, 1, 0, 0, ";", "#X", 0, 55, 72, 375, 4, 1, 0, 0, ";", "#X", 63, 77, 63, 10, 4, 1, 0, 0, ";", "#X", 62, 43, 56, 10, 4, 1, 0, 0, ";", "#X", 0, 76, 82, 10, 4, 1, 0, 0, ";", "#X", 63, 74, 80, 10, 4, 1, 0, 0, ";", "#X", 62, 50, 58, 10, 4, 1, 0, 0, ";", "#X", 125, 55, 63, 125, 4, 1, 0, 0, ";", "#X", 125, 72, 84, 167, 4, 1, 0, 0, ";", "#X", 0, 53, 83, 10, 4, 1, 0, 0, ";", "#X", 125, 41, 67, 875, 4, 1, 0, 0, ";", "#X", 42, 71, 89, 10, 4, 1, 0, 0, ";", "#X", 83, 48, 66, 10, 4, 1, 0, 0, ";", "#X", 84, 69, 100, 10, 4, 1, 0, 0, ";", "#X", 41, 53, 74, 10, 4, 1, 0, 0, ";", "#X", 125, 60, 63, 10, 4, 1, 0, 0, ";", "#X", 125, 69, 70, 10, 4, 1, 0, 0, ";", "#X", 125, 67, 61, 10, 4, 1, 0, 0, ";", "#X", 125, 65, 59, 10, 4, 1, 0, 0, ";", "#X", "stop", ";" ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-12", 0 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 1 ],
									"destination" : [ "obj-15", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-15", 1 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [ 109.5, 599.0, 201.0, 599.0, 201.0, 434.0, 122.5, 434.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 1 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 1 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-19", 0 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-19", 1 ],
									"destination" : [ "obj-20", 1 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 1 ],
									"destination" : [ "obj-17", 1 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 2 ],
									"destination" : [ "obj-17", 2 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 1 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [ 69.714287, 191.0, 229.5, 191.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 2 ],
									"destination" : [ "obj-16", 1 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [ 109.928574, 191.0, 266.5, 191.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 3 ],
									"destination" : [ "obj-16", 2 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [ 150.142853, 191.0, 303.5, 191.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 4 ],
									"destination" : [ "obj-16", 3 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [ 190.357147, 191.0, 340.5, 191.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-19", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
									"midpoints" : [ 89.5, 385.0, 395.0, 385.0, 395.0, 122.0, 29.5, 122.0 ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"fontname" : "Arial",
						"default_fontname" : "Arial",
						"globalpatchername" : "",
						"default_fontsize" : 14.0,
						"fontface" : 0,
						"fontsize" : 14.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "clear",
					"patching_rect" : [ 45.0, 165.0, 41.0, 21.0 ],
					"outlettype" : [ "" ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 14.0,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "romeo 75",
					"patching_rect" : [ 25.0, 245.0, 70.0, 23.0 ],
					"outlettype" : [ "list", "" ],
					"id" : "obj-1",
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 14.0,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"patching_rect" : [ 10.0, 8.0, 322.0, 64.0 ],
					"mode" : 1,
					"id" : "obj-24",
					"grad1" : [ 0.188235, 0.105882, 0.266667, 1.0 ],
					"background" : 1,
					"grad2" : [ 0.858824, 0.858824, 0.858824, 1.0 ],
					"numinlets" : 1,
					"numoutlets" : 0
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [ 114.5, 211.0, 34.5, 211.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-22", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [ 194.5, 211.0, 34.5, 211.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 1 ],
					"destination" : [ "obj-2", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
