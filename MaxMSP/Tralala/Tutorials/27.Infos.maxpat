{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 43.0, 127.0, 375.0, 363.0 ],
		"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
		"bglocked" : 0,
		"defrect" : [ 43.0, 127.0, 375.0, 363.0 ],
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
		"imprint" : 1,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "bpm 240",
					"patching_rect" : [ 46.0, 97.0, 65.0, 21.0 ],
					"numinlets" : 2,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 1,
					"bgcolor2" : [ 0.867, 0.867, 0.867, 1.0 ],
					"gradient" : 0,
					"outlettype" : [ "" ],
					"fontface" : 0,
					"background" : 0,
					"fontsize" : 14.0,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 0.0 ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"ignoreclick" : 0,
					"hidden" : 0,
					"id" : "obj-7"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "getxoffset",
					"patching_rect" : [ 89.0, 125.0, 71.0, 21.0 ],
					"numinlets" : 2,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 1,
					"bgcolor2" : [ 0.867, 0.867, 0.867, 1.0 ],
					"gradient" : 0,
					"outlettype" : [ "" ],
					"fontface" : 0,
					"background" : 0,
					"fontsize" : 14.0,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 0.0 ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"ignoreclick" : 0,
					"hidden" : 0,
					"id" : "obj-9"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "attributes",
					"patching_rect" : [ 127.0, 159.0, 68.0, 21.0 ],
					"numinlets" : 2,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 1,
					"bgcolor2" : [ 0.867, 0.867, 0.867, 1.0 ],
					"gradient" : 0,
					"outlettype" : [ "" ],
					"fontface" : 0,
					"background" : 0,
					"fontsize" : 14.0,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 0.0 ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"ignoreclick" : 0,
					"hidden" : 0,
					"id" : "obj-6"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "statistics",
					"patching_rect" : [ 155.0, 192.0, 64.0, 21.0 ],
					"numinlets" : 2,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 1,
					"bgcolor2" : [ 0.867, 0.867, 0.867, 1.0 ],
					"gradient" : 0,
					"outlettype" : [ "" ],
					"fontface" : 0,
					"background" : 0,
					"fontsize" : 14.0,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 0.0 ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"ignoreclick" : 0,
					"hidden" : 0,
					"id" : "obj-10"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print",
					"patching_rect" : [ 63.0, 293.0, 38.0, 23.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 0,
					"fontface" : 0,
					"background" : 0,
					"fontsize" : 14.0,
					"color" : [ 0.8, 0.84, 0.71, 1.0 ],
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"ignoreclick" : 0,
					"hidden" : 0,
					"id" : "obj-8"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"patching_rect" : [ 156.0, 231.0, 68.0, 23.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"fontface" : 0,
					"background" : 0,
					"fontsize" : 14.0,
					"color" : [ 0.8, 0.84, 0.71, 1.0 ],
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"ignoreclick" : 0,
					"hidden" : 1,
					"id" : "obj-5"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "recall",
					"patching_rect" : [ 156.0, 266.0, 44.0, 21.0 ],
					"numinlets" : 2,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 1,
					"bgcolor2" : [ 0.867, 0.867, 0.867, 1.0 ],
					"gradient" : 0,
					"outlettype" : [ "" ],
					"fontface" : 0,
					"background" : 0,
					"fontsize" : 14.0,
					"bgcolor" : [ 0.866667, 0.866667, 0.866667, 0.0 ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"ignoreclick" : 0,
					"hidden" : 1,
					"id" : "obj-3"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Infos",
					"frgb" : [ 0.93, 0.93, 0.97, 1.0 ],
					"patching_rect" : [ 13.0, 13.0, 138.0, 30.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 0,
					"fontface" : 3,
					"background" : 0,
					"fontsize" : 20.871338,
					"bgcolor" : [ 1.0, 1.0, 1.0, 0.0 ],
					"underline" : 0,
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.93, 0.93, 0.97, 1.0 ],
					"ignoreclick" : 1,
					"hidden" : 0,
					"id" : "obj-14"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "December 28, 2012",
					"frgb" : [ 0.93, 0.93, 0.97, 1.0 ],
					"patching_rect" : [ 13.0, 45.0, 227.0, 23.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 0,
					"fontface" : 0,
					"background" : 0,
					"fontsize" : 14.0,
					"bgcolor" : [ 1.0, 1.0, 1.0, 0.0 ],
					"underline" : 0,
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.93, 0.93, 0.97, 1.0 ],
					"ignoreclick" : 1,
					"hidden" : 0,
					"id" : "obj-4"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p",
					"patching_rect" : [ 46.0, 240.0, 42.0, 23.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"presentation" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontface" : 0,
					"background" : 0,
					"fontsize" : 14.0,
					"color" : [ 0.827451, 0.737255, 0.835294, 1.0 ],
					"bgcolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"ignoreclick" : 0,
					"hidden" : 0,
					"id" : "obj-1",
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 554.0, 167.0, 403.0, 330.0 ],
						"bglocked" : 0,
						"defrect" : [ 554.0, 167.0, 403.0, 330.0 ],
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
									"maxclass" : "outlet",
									"patching_rect" : [ 360.0, 280.0, 25.0, 25.0 ],
									"numinlets" : 1,
									"numoutlets" : 0,
									"id" : "obj-3",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"patching_rect" : [ 20.0, 20.0, 25.0, 25.0 ],
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"id" : "obj-2",
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "tralala",
									"patching_rect" : [ 20.0, 60.0, 350.0, 200.0 ],
									"numinlets" : 1,
									"numoutlets" : 5,
									"outlettype" : [ "list", "", "", "bang", "" ],
									"yoffset" : 649,
									"id" : "obj-1",
									"tralala" : 									{
										"untitled" : 										{
											"bpm" : [ "bpm", 180 ],
											"chance" : [ "chance", 100 ],
											"velocity" : [ "velocity", 0 ],
											"channel" : [ "channel", 1 ],
											"chord" : [ "chord", 0 ],
											"cell" : [ "cell", 12 ],
											"value" : [ "value", 6 ],
											"scale" : [ "scale", "C", "natural" ],
											"zone" : [ "zone", 0, 96, 60, 71 ],
											"0" : [ "note", 36, 64, 78, 6, 0 ],
											"1" : [ "note", 72, 67, 86, 6, 0 ],
											"2" : [ "note", 0, 71, 86, 6, 0 ],
											"3" : [ "note", 12, 60, 74, 6, 0 ],
											"4" : [ "note", 24, 66, 78, 6, 0 ],
											"5" : [ "note", 60, 62, 80, 6, 0 ],
											"6" : [ "note", 48, 69, 79, 6, 0 ],
											"7" : [ "note", 84, 60, 80, 6, 0 ]
										}

									}

								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 4 ],
									"destination" : [ "obj-3", 0 ],
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
					"maxclass" : "panel",
					"patching_rect" : [ 10.0, 9.0, 355.0, 64.0 ],
					"numinlets" : 1,
					"mode" : 1,
					"presentation" : 0,
					"border" : 0,
					"rounded" : 8,
					"numoutlets" : 0,
					"grad1" : [ 0.188235, 0.105882, 0.266667, 1.0 ],
					"shadow" : 0,
					"background" : 1,
					"bordercolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"grad2" : [ 0.858824, 0.858824, 0.858824, 1.0 ],
					"angle" : 0.0,
					"bgcolor" : [ 0.66667, 0.66667, 0.66667, 1.0 ],
					"presentation_rect" : [ 0.0, 0.0, 0.0, 0.0 ],
					"ignoreclick" : 1,
					"hidden" : 0,
					"id" : "obj-23"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 1,
					"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 1,
					"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-1", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-6", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"color" : [ 0.694118, 0.694118, 0.694118, 1.0 ],
					"midpoints" : [  ]
				}

			}
 ]
	}

}
