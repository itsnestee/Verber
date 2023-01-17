Content.makeFrontInterface(600, 600);

Synth.deferCallbacks(true);

//COLOR ASSETS
const nOffWhite = 0xfffaf9f6;
const nBlack = 0xff121212;

//IMAGE POSITIONING
reg pinkHeight = -70;
reg blueHeight = 120;

//POSITION SHIFTER
reg ppixelCounter = -1;
reg bPixelCounter = 1;


const var Panel1 = Content.getComponent("Panel1");
const var Panel2 = Content.getComponent("Panel2");

Panel2.setValue(0);
var switchTrigger = 0;
var textOpacityScaler = 0.1;


//IMAGE ASSETS 
Panel1.loadImage("{PROJECT_FOLDER}pnkell.png", "pink");
Panel1.loadImage("{PROJECT_FOLDER}blueEll.png", "blue");


Panel1.setPaintRoutine(function(g)
{
	g.fillAll(nBlack);
	g.drawImage("pink", [60, pinkHeight, 540, 650], 0, 0);
	g.drawImage("blue", [-50, blueHeight, 570, 680], 0, 0);
});

Panel2.setPaintRoutine(function(g)
{
	if(switchTrigger == 1)
	{
		 var textWidth = 650;
		 var textHeight = 50;
		 
		 var xBalancer = textWidth / 2;
		 var yBalancer = textHeight / 2;
		

		g.fillAll(0xB0121212);
		g.setColour(nOffWhite);
		g.setOpacity(1.0 - textOpacityScaler);
		g.setFont("Actay Wide", textOpacityScaler * 80);
		g.drawAlignedText("INTELLIVERB!", [(this.getWidth() / 2) - xBalancer, 
										   (this.getHeight() / 2) - yBalancer, textWidth, textHeight], 					"centred");
	}
	else{
		g.fillAll(0x00000000);
	}
});


//TIMER ITERATION
function intelliSwitcher()
{
	var incrementer = Panel2.getValue();
	
	
	incrementer += 1;
	textOpacityScaler += 0.1;
	
	Panel2.setValue(incrementer);
	
	if(incrementer >= 10)
	{
		Panel2.stopTimer();	
		switchTrigger = 0;
		textOpacityScaler = 0.1;
		Panel2.setValue(0);
	}
		
	Panel2.repaint();
}




Panel1.setTimerCallback(function(){
	if((pinkHeight == -70) && (blueHeight == 120))
	{
		ppixelCounter =  1;
		bPixelCounter = -1;
	}
	
	if((pinkHeight >= 118) && (blueHeight <= 2))
	{
		ppixelCounter = -1;
		bPixelCounter =  1;	
	}
	
	pinkHeight = pinkHeight + ppixelCounter;
	blueHeight = blueHeight + bPixelCounter;
	
	this.repaint();
});

//Panel1.startTimer(100);



const var btnIntelliOnOff = Content.getComponent("btnIntelliOnOff");
const var knbVerb = Content.getComponent("knbVerb");
const var intelliVerb = Content.getComponent("intelliVerb");


inline function onbtnIntelliOnOffControl(component, value)
{
	if(value == 1)
	{
		switchTrigger = 1;
		Panel2.startTimer(75);
		Panel2.setTimerCallback(intelliSwitcher);

		knbVerb.set("visible", 0);
		intelliVerb.set("visible", 1);
	}
	else
	{
		knbVerb.set("visible", 1);
		intelliVerb.set("visible", 0);
	}
};

Content.getComponent("btnIntelliOnOff").setControlCallback(onbtnIntelliOnOffControl);






















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
		
	
		
	g.setFont("Actay Wide", 15);
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
 		
 		g.setColour(obj.bgColour);
 		g.setOpacity( 1.0 - (obj.value * 0.8));
 		g.fillRect([ x + 1, h - 5, w / 10, h / 10]);
 		g.setColour(obj.bgColour);
 		g.setOpacity((obj.value * 0.8) + 0.2);
 		g.fillRect([ w - 6, h - 5, w / 10, h / 10]);
 		
 		g.setColour(nOffWhite);
 		g.setOpacity(0.4);
 		g.drawEllipse([ x + 2, y + 2, w - (w / 12.5), h - (h / 12.5)], 2.5);
 		
 		g.rotate(end, [w / 2, h / 2]);
 		    g.setColour(nOffWhite);
 		    g.setOpacity(0.4);
 		g.fillRoundedRectangle([(w / 2) - (2 / 2), 3, 3, 20], 2);
 		

});


const var btnPluPredelay = Content.getComponent("btnPluPredelay");
const var btnMinusPredelay = Content.getComponent("btnMinusPredelay");




//PREDELAY SECTION
var tempoSignature = 0;
const var lbPredelayTempo = Content.getComponent("lbPredelayTempo");



inline function onbtnPluPredelayControl(component, value)
{	
	if(value == 1) //Incrementing tempoSignature
	{
		tempoSignature += 1;
	
	}
	
	if(tempoSignature > 4) //Cheching if tempoSignature is > 4 or < 0
		tempoSignature = 0;
	else if(tempoSignature < 0)
		tempoSignature = 4;
	
	switch(tempoSignature) { //Switch cases base on tempoSignature's value
		case 0: 
			lbPredelayTempo.set("text" , "1/1");
			break;
		
		case 1:
			lbPredelayTempo.set("text" , "1/2");
			break;
		
		case 2:
			lbPredelayTempo.set("text" , "1/4");
			break;
		case 3:
			lbPredelayTempo.set("text" , "1/8");
			break;
		
		case 4:
			lbPredelayTempo.set("text" , "1/16");
			break;
	}

};

Content.getComponent("btnPluPredelay").setControlCallback(onbtnPluPredelayControl);



inline function onbtnMinusPredelayControl(component, value)
{
	if(value == 1) //Decrementing tempoSignature
	{
		tempoSignature -= 1;

	}
	
	if(tempoSignature > 4) //Cheching if tempoSignature is > 4 or < 0
		tempoSignature = 0;
	else if(tempoSignature < 0)
		tempoSignature = 4;
	
	switch(tempoSignature) { //Switch cases base on tempoSignature's value
		case 0: 
			lbPredelayTempo.set("text" , "1/1");
			break;
		
		case 1:
			lbPredelayTempo.set("text" , "1/2");
			break;
		
		case 2:
			lbPredelayTempo.set("text" , "1/4");
			break;
		case 3:
			lbPredelayTempo.set("text" , "1/8");
			break;
		
		case 4:
			lbPredelayTempo.set("text" , "1/16");
			break;
	}
};

Content.getComponent("btnMinusPredelay").setControlCallback(onbtnMinusPredelayControl);




const var Label1 = Content.getComponent("Label1");
const var Label2 = Content.getComponent("Label2");
const var Label3 = Content.getComponent("Label3");

const var Knob1 = Content.getComponent("knob1");
const var Knob2 = Content.getComponent("Knob2");
const var Knob3 = Content.getComponent("Knob3");

var labels = [ Label1, Label2, Label3 ];
var knobs =  [ Knob1, Knob2, Knob3 ];


for(i = 0; i < knobs.length; i++){
	labels[i].set("text", knobs[i].get("text"));
}


const var labelsTimer = Engine.createTimerObject();


labelsTimer.setTimerCallback(function(){
	for(i = 0; i < knobs.length; i++){
		labels[i].set("text", knobs[i].get("text"));
	}
	labels[i].changed;
	
	labelsTimer.stopTimer();
});

reg listener = 0;

inline function onknob1Control(component, value)
{
	labelsTimer.startTimer(400);
	if (listener == 1)
		labels[0].set("text", Math.round(value) + knobs[0].get("suffix"));
		labels[0].changed();
		listener = 1;
		
	//SETVALUE TO GAIN BEFORE REVERB

	
}

Knob1.setControlCallback(onknob1Control);



inline function onKnob2Control(component, value)
{
	labelsTimer.startTimer(400);
	if (listener == 1)
		labels[1].set("text", Math.round(value) + knobs[1].get("suffix"));
		labels[1].changed();
		listener = 1;
		
	//SETVALUE TO CROSSFADE REVERB
};

Knob2.setControlCallback(onKnob2Control);



inline function onKnob3Control(component, value)
{
	labelsTimer.startTimer(400);
	if (listener == 1)
		labels[2].set("text", Math.round(value) + knobs[2].get("suffix"));
		labels[2].changed();
		listener = 1;
		
	//SET VALUE TO THE REVERB TIME
		
};

Knob3.setControlCallback(onKnob3Control);



//OPEN INSTA

inline function onbtnInstaControl(component, value)
{
	if(value == 1)
	{
		Engine.openWebsite("https://www.instagram.com/itsnestee/");	
	}

	
};

Content.getComponent("btnInsta").setControlCallback(onbtnInstaControl);






//DSP VALUE GETTER
const var Panel3 = Content.getComponent("Panel3");
const var DSPTEST = Synth.getEffect("DSPTEST");

const var gm = Engine.getGlobalRoutingManager();
const var cable = gm.getCable("gainValue");

global gainListener = 0;
Panel3.data.activator = 0;
global bufferValue = 0;

global levTimer = Engine.createTimerObject();

levTimer.setTimerCallback(function(){
	
	inline function onCableChange(value)
	{
		gainListener = 1;
	
		bufferValue = value;
		Console.print(value);
	}

});
cable.registerCallback(onCableChange, false);

Panel3.setTimerCallback(function()
{
	if(gainListener == 1){
		Panel3.data.activator = 1;	
	}

	Panel3.repaint();
});


Panel3.setPaintRoutine(function(g)
{
	if(Panel3.data.activator == 1)
		g.setColour(nOffWhite);
		g.setFont("Actay Wide", 10.0);
		g.drawAlignedText(bufferValue, [0,0,this.getWidth(), this.getHeight()], "left");
});



Panel3.startTimer(20);function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 