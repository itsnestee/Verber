const laf = Engine.createGlobalScriptLookAndFeel();


//BUTTON
laf.registerFunction("drawToggleButton", function(g, obj)
{
		//Hover == 1 && Pressed == 0
		g.setColour(obj.over ? Colours.fromVec4([0.98, 0.976, 0.965, 0.07]) 
					: Colours.fromVec4([0.98, 0.976, 0.965, 0.03]));
		
		//Hover == 1 && Pressed == 1			
		if(obj.value)
		{
			g.setColour(obj.over ? Colours.fromVec4([0.98, 0.976, 0.965, 0.2]) 
					: Colours.fromVec4([0.98, 0.976, 0.965, 0.1]));
		}
		

		
		g.fillRoundedRectangle(obj.area, 5);
		
		g.setColour(obj.over ? Colours.fromVec4([0.98, 0.976, 0.965, 0.8]) 
					: Colours.fromVec4([0.98, 0.976, 0.965, 0.3]));
					
				
		
		//Hover == 1 && Pressed == 1 FOR TEXT
		if(obj.value)
		{
			g.setColour(obj.over ? Colours.fromVec4([0.98, 0.976, 0.965, 1.0]) 
				: Colours.fromVec4([0.98, 0.976, 0.965, 0.9]));
				
		}
		
	
		
	g.setFont("Lexend", 15);
	g.drawText(obj.text, obj.area );
	
});

//KNOB
laf.registerFunction("drawRotarySlider", function(g, obj)
 {
 		var a = obj.area;
 		var x = a[0];
 		var y = a[1];
 		var w = a[2];
 		var h = a[3];
 		
 		var start = 2.5;
 		var end = start * 2 * obj.valueNormalized - start;
 		
 		if(obj.text.indexOf("AMOUNT") != -1)
 		{
	 		g.setColour(obj.bgColour);
	 		if(btnIntelliverbPower.getValue() == 1)
	 		{
		 		g.setOpacity(1.0);
		 		g.fillRect([ x + 1, h - 5, w / 10, h / 10]);
		 		g.fillRect([ w - 6, h - 5, w / 10, h / 10]);
	 		}
	 		else
	 		{
		 		g.setOpacity(0.5);
		 		g.fillRect([ x + 1, h - 5, w / 10, h / 10]);
		 		g.fillRect([ w - 6, h - 5, w / 10, h / 10]);	
	 		}
	 		
	 		
	 		g.setColour(nOffWhite);
	 		g.setOpacity(0.4);
	 		g.drawEllipse([ x + 2, y + 2, w - (w / 12.5), h - (h / 12.5)], 2.5);
	 		
	 		g.rotate(end, [w / 2, h / 2]);
	 		    g.setColour(nOffWhite);
	 		    g.setOpacity(0.4);
	 		g.fillRoundedRectangle([(w / 2) - (2 / 2), 3, 3, 20], 2);
 		}
 		else
 		{
	 		g.setColour(obj.bgColour);
	 		g.setOpacity( 1.0 - (obj.value / 100) + 0.2);
	 		g.fillRect([ x + 1, h - 5, w / 10, h / 10]);
	 		g.setColour(obj.bgColour);
	 		g.setOpacity(((obj.value / 100) * 0.8) + 0.2);
	 		g.fillRect([ w - 6, h - 5, w / 10, h / 10]);
	 		
	 		g.setColour(nOffWhite);
	 		g.setOpacity(0.4);
	 		g.drawEllipse([ x + 2, y + 2, w - (w / 12.5), h - (h / 12.5)], 2.5);
	 		
	 		g.rotate(end, [w / 2, h / 2]);
	 		    g.setColour(nOffWhite);
	 		    g.setOpacity(0.4);
	 		g.fillRoundedRectangle([(w / 2) - (2 / 2), 3, 3, 20], 2);
 		}

 		

});
