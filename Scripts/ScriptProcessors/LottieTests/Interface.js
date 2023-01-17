Content.makeFrontInterface(600, 600);


const lottie = "579.nT6K8CFYLzbD.XUkAABPKQe7osUDEhiODAQM+.N+tdCR13dZZx8jVrllwvv1whC.2.PN.rPgjdmVqr4TBBez15roJcNb3vin4zJ13ilg0mfOZHllS9iO55Ryo9oLTtEZN0Kd5HqCz7Q67zKB2mYUB87jlvi7pLOnw9+4fvU1X8mSt+HVuB49Gk3bxcYuno4TSoJT.G.yookJWdFQ1+vv3iVwsm3eCYpP8xGsRunoQbkFzSHIBnFqj.Gz0ZQMUKtfbxgOkg6UOnwJAys4j+b5EYA.Ek7OiiovoZHw9APTT2.yCyi.Inb69Nc9GFcw08tL4jAyiFtqAWu3y8KUqwLVPW0fOjsfsOpRoLuRSW5nnDHIHo.fBBZTIcpw.V.PCD.Tf.RQCU0.9vqHRNwePtnrcJzlVFB8P5IUM7k6EUji9Pl3iZH3u+HGJBZhKXn4VAWnD3jPAAEtGtz9bTqtT7SfaEsMpnrP+5OXEPRP2glPDqwcFxex+aryEdKrsqt4pb5KCR0x.wspxgKTyzELDgEZLY4sdTQAgJoVO7zq0NsfDhPTLq1hX0cIHn+tl0+wyXLH7LsfAhTrqlSyKQCXd0TRQN45B+bDD0tQEye5tolvkvAvOTPqhKk.XbO4q3qVh1EdWzv.x1bzLTx1WXKaOoohZtkqtDK+uNFk3vZo7WSLXqPLbHCx01VgGKegVm.ap1zCqNqgELClAxe86I1GvWlUDWbT8IRV60fH7rFpUcVI+cz24RQJIio2MuxFaYVKANC2X8xC";


const var Panel1 = Content.getComponent("Panel1");

Panel1.setAnimation(lottie);

const data = Panel1.getAnimationData();

inline function onKnob1Control(component, value)
{
	Panel1.setAnimationFrame(value);
	
};

Content.getComponent("Knob1").setControlCallback(onKnob1Control);
function onNoteOn()
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
 