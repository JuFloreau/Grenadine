{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 186.0, 191.0, 439.0, 448.0 ],
		"bglocked" : 0,
		"defrect" : [ 186.0, 191.0, 439.0, 448.0 ],
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
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "rotate",
					"patching_rect" : [ 240.0, 100.0, 46.0, 21.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 14.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-9"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"patching_rect" : [ 80.0, 120.0, 20.0, 20.0 ],
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"id" : "obj-5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "bpm 240",
					"patching_rect" : [ 180.0, 60.0, 65.0, 21.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 14.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "0 60, 12 61, 24 62, 36 63, 48 64, 60 65, 72 66, 84 67",
					"patching_rect" : [ 60.0, 20.0, 337.0, 21.0 ],
					"fontname" : "Arial",
					"numinlets" : 2,
					"fontsize" : 14.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-11"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "prepend note",
					"patching_rect" : [ 60.0, 60.0, 93.0, 23.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 14.0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"id" : "obj-12"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p MIDI",
					"patching_rect" : [ 100.0, 400.0, 52.0, 23.0 ],
					"fontname" : "Arial",
					"numinlets" : 0,
					"fontsize" : 14.0,
					"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
					"numoutlets" : 0,
					"id" : "obj-7",
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 372.0, 216.0, 267.0, 216.0 ],
						"bglocked" : 0,
						"defrect" : [ 372.0, 216.0, 267.0, 216.0 ],
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
									"patching_rect" : [ 20.0, 120.0, 22.0, 23.0 ],
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 14.0,
									"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"id" : "obj-6",
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 495.0, 187.0, 125.0, 343.0 ],
										"bglocked" : 0,
										"defrect" : [ 495.0, 187.0, 125.0, 343.0 ],
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
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"id" : "obj-9"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"patching_rect" : [ 20.0, 300.0, 25.0, 25.0 ],
													"numinlets" : 1,
													"numoutlets" : 0,
													"id" : "obj-7",
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pack",
													"patching_rect" : [ 20.0, 260.0, 40.0, 23.0 ],
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"id" : "obj-6"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b i",
													"patching_rect" : [ 20.0, 180.0, 40.0, 23.0 ],
													"fontname" : "Arial",
													"numinlets" : 1,
													"fontsize" : 14.0,
													"numoutlets" : 2,
													"outlettype" : [ "bang", "int" ],
													"id" : "obj-5"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 16",
													"patching_rect" : [ 20.0, 140.0, 48.0, 23.0 ],
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 3,
													"outlettype" : [ "bang", "bang", "int" ],
													"id" : "obj-4"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "int",
													"patching_rect" : [ 80.0, 220.0, 32.5, 23.0 ],
													"fontname" : "Arial",
													"numinlets" : 2,
													"fontsize" : 14.0,
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"id" : "obj-3"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b i",
													"patching_rect" : [ 20.0, 100.0, 54.0, 23.0 ],
													"fontname" : "Arial",
													"numinlets" : 1,
													"fontsize" : 14.0,
													"numoutlets" : 2,
													"outlettype" : [ "bang", "int" ],
													"id" : "obj-2"
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"id" : "obj-1",
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
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-4", 0 ],
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
 ]
									}
,
									"saved_object_attributes" : 									{
										"fontname" : "Arial",
										"default_fontface" : 0,
										"globalpatchername" : "",
										"default_fontname" : "Arial",
										"fontface" : 0,
										"fontsize" : 14.0,
										"default_fontsize" : 14.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadmess 4",
									"patching_rect" : [ 60.0, 80.0, 82.0, 23.0 ],
									"fontname" : "Arial",
									"numinlets" : 1,
									"fontsize" : 14.0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"id" : "obj-10"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "umenu",
									"patching_rect" : [ 20.0, 40.0, 116.0, 25.0 ],
									"fontname" : "Arial",
									"arrowframe" : 0,
									"textcolor2" : [ 0.0, 0.0, 0.0, 1.0 ],
									"numinlets" : 1,
									"bgcolor2" : [ 0.917647, 0.937255, 0.670588, 1.0 ],
									"hltcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
									"types" : [  ],
									"fontsize" : 16.0,
									"align" : 1,
									"numoutlets" : 3,
									"items" : [ "Grand", "Piano", ",", "Bright", "Piano", ",", "Electric", "Grand", ",", "Honkytonk", "Piano", ",", "Electric", "Piano", 1, ",", "Electric", "Piano", 2, ",", "Harpsichord", ",", "Clavinet", ",", "Celesta", ",", "Glockenspiel", ",", "Music", "Box", ",", "Vibraphone", ",", "Marimba", ",", "Xylophone", ",", "Tubular", "Bell", ",", "Dulcimer", ",", "Drawbar", "Organ", ",", "Percussive", "Organ", ",", "Rock", "Organ", ",", "Church", "Organ", ",", "Reed", "Organ", ",", "Accordion", ",", "Harmonica", ",", "Tango", "Accordion", ",", "Nylon", "String", "Guitar", ",", "Steel", "String", "Guitar", ",", "Jazz", "Guitar", ",", "Clean", "Guitar", ",", "Muted", "Guitar", ",", "Overdrive", "Guitar", ",", "Distortion", "Guitar", ",", "Guitar", "Harmonics", ",", "Acoustic", "Bass", ",", "Fingered", "Bass", ",", "Picked", "Bass", ",", "Fretless", "Bass", ",", "Slap", "Bass", 1, ",", "Slap", "Bass", 2, ",", "Synth", "Bass", 1, ",", "Synth", "Bass", 2, ",", "Violin", ",", "Viola", ",", "Cello", ",", "Contrabass", ",", "Tremolo", "Strings", ",", "Pizzicato", "Strings", ",", "Harp", ",", "Timpani", ",", "String", "Ensemble", ",", "Slow", "Strings", ",", "Synth", "Strings", 1, ",", "Synth", "Strings", 2, ",", "Choir", "Aahs", ",", "Voice", "Oohs", ",", "Synth", "Vox", ",", "Orchestra", "Hit", ",", "Trumpet", ",", "Trombone", ",", "Tuba", ",", "Muted", "Trumpet", ",", "French", "Horn", ",", "Brass", 1, ",", "Synth", "Brass", 1, ",", "Synth", "Brass", 2, ",", "Soprano", "Sax", ",", "Alto", "Sax", ",", "Tenor", "Sax", ",", "Baritone", "Sax", ",", "Oboe", ",", "English", "Horn", ",", "Bassoon", ",", "Clarinet", ",", "Piccolo", ",", "Flute", ",", "Recorder", ",", "Pan", "Flute", ",", "Blown", "Bottle", ",", "Shakuhachi", ",", "Whistle", ",", "Ocarina", ",", "Square", "Wave", ",", "Sawtooth", "Wave", ",", "Synth", "Calliope", ",", "Chiffer", "Lead", ",", "Charang", ",", "Solo", "Vox", ",", "5th", "Sawtooth", "Wave", ",", "Bass", "and", "Lead", ",", "Fantasia", ",", "Warm", "Pad", ",", "Polysynth", ",", "Space", "Voice", ",", "Bowed", "Glass", ",", "Metal", "Pad", ",", "Halo", "Pad", ",", "Sweep", "Pad", ",", "Ice", "Rain", ",", "Soundtrack", ",", "Crystal", ",", "Atmosphere", ",", "Brightness", ",", "Goblin", ",", "Echo", "Drops", ",", "Star", "Theme", ",", "Sitar", ",", "Banjo", ",", "Shamisen", ",", "Koto", ",", "Kalimba", ",", "Bag", "Pipe", ",", "Fiddle", ",", "Shanai", ",", "Tinkle", "Bell", ",", "Agogo", ",", "Steel", "Drums", ",", "Woodblock", ",", "Taiko", ",", "Melo", "Tom", ",", "Synth", "Drum", ",", "Reverse", "Cymbal", ",", "Guitar", "Fret", "Noise", ",", "Breath", "Noise", ",", "Seashore", ",", "Bird", ",", "Telephone", ",", "Helicopter", ",", "Applause", ",", "Gun", "Shot" ],
									"framecolor" : [ 0.827451, 0.827451, 0.827451, 0.0 ],
									"bgcolor" : [ 0.827451, 0.737255, 0.835294, 0.0 ],
									"outlettype" : [ "int", "", "" ],
									"arrow" : 0,
									"id" : "obj-11"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pgmout",
									"patching_rect" : [ 20.0, 160.0, 57.0, 23.0 ],
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 14.0,
									"numoutlets" : 0,
									"id" : "obj-12"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "freebang",
									"patching_rect" : [ 160.0, 40.0, 66.0, 23.0 ],
									"fontname" : "Arial",
									"numinlets" : 0,
									"fontsize" : 14.0,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"id" : "obj-21"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "i 0",
									"patching_rect" : [ 160.0, 120.0, 36.0, 23.0 ],
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 14.0,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"id" : "obj-18"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "uzi 16 1",
									"patching_rect" : [ 160.0, 80.0, 72.0, 23.0 ],
									"fontname" : "Arial",
									"numinlets" : 2,
									"fontsize" : 14.0,
									"numoutlets" : 3,
									"outlettype" : [ "bang", "bang", "int" ],
									"id" : "obj-17"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "ctlout 123",
									"patching_rect" : [ 160.0, 160.0, 72.0, 23.0 ],
									"fontname" : "Arial",
									"numinlets" : 3,
									"fontsize" : 14.0,
									"numoutlets" : 0,
									"id" : "obj-19"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 0 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-18", 0 ],
									"destination" : [ "obj-19", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 2 ],
									"destination" : [ "obj-19", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"fontname" : "Arial",
						"default_fontface" : 0,
						"globalpatchername" : "",
						"default_fontname" : "Arial",
						"fontface" : 0,
						"fontsize" : 14.0,
						"default_fontsize" : 14.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p",
					"patching_rect" : [ 60.0, 400.0, 24.0, 23.0 ],
					"fontname" : "Arial",
					"numinlets" : 1,
					"fontsize" : 14.0,
					"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
					"numoutlets" : 0,
					"id" : "obj-14",
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 416.0, 128.0, 363.0, 215.0 ],
						"bglocked" : 0,
						"defrect" : [ 416.0, 128.0, 363.0, 215.0 ],
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
									"text" : "noteout",
									"patching_rect" : [ 50.0, 140.0, 254.0, 23.0 ],
									"fontname" : "Arial",
									"numinlets" : 3,
									"fontsize" : 14.0,
									"numoutlets" : 0,
									"id" : "obj-10"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "makenote 60 90 250 1 @repeatmode 1",
									"patching_rect" : [ 50.0, 100.0, 254.0, 23.0 ],
									"fontname" : "Arial",
									"numinlets" : 4,
									"fontsize" : 14.0,
									"numoutlets" : 3,
									"outlettype" : [ "float", "float", "float" ],
									"id" : "obj-9"
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "list" ],
									"id" : "obj-13",
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 1 ],
									"destination" : [ "obj-10", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 2 ],
									"destination" : [ "obj-10", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"fontname" : "Arial",
						"default_fontface" : 0,
						"globalpatchername" : "",
						"default_fontname" : "Arial",
						"fontface" : 0,
						"fontsize" : 14.0,
						"default_fontsize" : 14.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "tralala",
					"patching_rect" : [ 60.0, 180.0, 259.0, 197.0 ],
					"yoffset" : 649,
					"numinlets" : 1,
					"color" : [ 0.392157, 0.278431, 0.376471, 1.0 ],
					"numoutlets" : 4,
					"outlettype" : [ "list", "", "", "bang" ],
					"xoffset" : -62,
					"id" : "obj-1",
					"tralala" : 					{

					}

				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
