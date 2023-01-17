var tempoSignature = 0;
var duckingAmount = 0;

//LABELS REFERENCES
const var Label1 = Content.getComponent("Label1");
const var Label2 = Content.getComponent("Label2");
const var Label3 = Content.getComponent("Label3");
var labels = [ Label1, Label2, Label3 ];
reg labelListener = 0;

//KNOBS REFERENCES 

const var Knob2 = Content.getComponent("Knob2");
const var Knob3 = Content.getComponent("Knob3");
var knobs =  [  Knob2, Knob3 ];
var duckingAwareness = 0;

//Predelay Button References
const var btnPluPredelay = Content.getComponent("btnPluPredelay");
const var btnMinusPredelay = Content.getComponent("btnMinusPredelay");

Engine.loadFontAs("{PROJECT_FOLDER}ActayWide-Bold.ttf", "Actay");
Engine.setGlobalFont("Actay");


//PREDELAY FUNCTIONS
inline function increaseTempoSignature(component, value)
{
	if(value == 1) 
	{
		tempoSignature += 1;

	}
	
	if(tempoSignature > 5) 
		tempoSignature = 0;
	else if(tempoSignature < 0)
		tempoSignature = 5;
	switch(tempoSignature) { 
		case 0: 
			lbPredelayTempo.set("text" , "None");
			VERBERV.setAttribute(VERBERV.DelayTime, 0);
			break;
		
		case 1:
			lbPredelayTempo.set("text" , "1/4");
			VERBERV.setAttribute(VERBERV.DelayTime, 1000);
			break;
		
		case 2:
			lbPredelayTempo.set("text" , "1/8");
			VERBERV.setAttribute(VERBERV.DelayTime, 500);
			break;
		case 3:
			lbPredelayTempo.set("text" , "1/16");
			VERBERV.setAttribute(VERBERV.DelayTime, 250);
			break;
		
		case 4:
			lbPredelayTempo.set("text" , "1/32");
			VERBERV.setAttribute(VERBERV.DelayTime, 125);
			break;
		
		case 5:
			lbPredelayTempo.set("text" , "1/64");
			VERBERV.setAttribute(VERBERV.DelayTime, 63);
			break;			
		
	}

};

inline function decreaseTempoSignature(component, value)
{
	if(value == 1) 
	{
		tempoSignature -= 1;

	}
	
	if(tempoSignature > 5) 
		tempoSignature = 0;
	else if(tempoSignature < 0)
		tempoSignature = 5;
	switch(tempoSignature) { 
		case 0: 
			lbPredelayTempo.set("text" , "None");
			VERBERV.setAttribute(VERBERV.DelayTime, 0);
			break;
		
		case 1:
			lbPredelayTempo.set("text" , "1/4");
			VERBERV.setAttribute(VERBERV.DelayTime, 1000);
			break;
		
		case 2:
			lbPredelayTempo.set("text" , "1/8");
			VERBERV.setAttribute(VERBERV.DelayTime, 500);
			break;
		case 3:
			lbPredelayTempo.set("text" , "1/16");
			VERBERV.setAttribute(VERBERV.DelayTime, 250);
			break;
		
		case 4:
			lbPredelayTempo.set("text" , "1/32");
			VERBERV.setAttribute(VERBERV.DelayTime, 125);
			break;
		
		case 5:
			lbPredelayTempo.set("text" , "1/64");
			VERBERV.setAttribute(VERBERV.DelayTime, 34);
			break;	
	}

};


//DUCKING CHANGES
inline function increaseDuckingAmount(component, value)
{
	if(value == 1) 
	{
		duckingAmount += 1;
	
	}
	
	if(duckingAmount > 4) 
		duckingAmount = 0;
	else if(duckingAmount < 0)
		duckingAmount = 4;
		
		
	switch(duckingAmount) { 
		case 0: 
			lbduckingAmount.set("text" , "1X");
			duckingAwareness = 1;
			break;
		
		case 1:
			lbduckingAmount.set("text" , "2X");
			duckingAwareness = 2;
			break;
		
		case 2:
			lbduckingAmount.set("text" , "3X");
			duckingAwareness = 3;
			break;
		case 3:
			lbduckingAmount.set("text" , "4X");
			duckingAwareness = 4;
			break;
		
		case 4:
			lbduckingAmount.set("text" , "5X");
			duckingAwareness = 5;
			break;
	
		

	}

}


inline function decreaseDuckingAmount(component, value)
{
	if(value == 1) 
	{
		duckingAmount -= 1;
	
	}
	
	if(duckingAmount > 4) 
		duckingAmount = 0;
	else if(duckingAmount < 0)
		duckingAmount = 4;
		
		
	switch(duckingAmount) { 
		case 0: 
			lbduckingAmount.set("text" , "1X");
			duckingAwareness = 1;
			break;
		
		case 1:
			lbduckingAmount.set("text" , "2X");
			duckingAwareness = 2;
			break;
		
		case 2:
			lbduckingAmount.set("text" , "3X");
			duckingAwareness = 3;
			break;
		case 3:
			lbduckingAmount.set("text" , "4X");
			duckingAwareness = 4;
			break;
		
		case 4:
			lbduckingAmount.set("text" , "5X");
			duckingAwareness = 5;
			break;
	
		
	
	}	
}







//KNOB CONTROLS FUNCTIONS
inline function setAwareness(component, value)
{
	duckingAwareness = value;
};

inline function setBlend(component, value)
{	
	if(btnIntelliverbPower.getValue() == 1)
	{
		VERBERV.setAttribute(VERBERV.Blend, value / 175);
		Knob2.changed();	
	}
	else{
		VERBERV.setAttribute(VERBERV.Blend, value / 100);
		Knob2.changed();
	}
		
};

inline function setBigness(component, value)
{
	VERBERV.setAttribute(VERBERV.Space, 1 - (value / 100));
	VERBERV.setAttribute(VERBERV.Feedback, value / 100);
};

//KNOB CALLBACKS
Knob2.setControlCallback(setBlend);
Knob3.setControlCallback(setBigness);

//PREDELAY GUI REFERENCES/CALLBACKS
Content.getComponent("btnPluPredelay").setControlCallback(increaseTempoSignature);
Content.getComponent("btnMinusPredelay").setControlCallback(decreaseTempoSignature);
const var lbPredelayTempo = Content.getComponent("lbPredelayTempo");


//DUCKING GUI REFERENCES/CALLBACKS
Content.getComponent("btnPluDucking").setControlCallback(increaseDuckingAmount);
Content.getComponent("btnMinusDucking").setControlCallback(decreaseDuckingAmount);
const var lbduckingAmount = Content.getComponent("lbduckingAmount");



//INTELLIVERB UI REFERENCES / CALLBACKS
Content.getComponent("btnIntelliOnOff").setControlCallback(onIntelliverbPower);
const var btnIntelliverbPower = Content.getComponent("btnIntelliOnOff");//used in LAF to colour knob, do not touch it

//INSTAGRAM BUTTON REFERENCE / CALLBACK
Content.getComponent("btnInsta").setControlCallback(openInstagram);

