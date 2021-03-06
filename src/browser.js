const electron = require('electron');
const webFrame = electron.webFrame;

webFrame.setZoomFactor(1.3)

//0.8

document.addEventListener('DOMContentLoaded', async () => {
	
  var style = document.createElement('style');
	
  document.head.appendChild(style);
	
  style.sheet.insertRule('::-webkit-scrollbar { width: 0px; }');

  setInterval(function(){ DisableVideo();}, 500);
	
  setInterval(function(){ RemoveSideBar();}, 500);
	
  setTimeout(() => {  document.documentElement.classList.toggle('__fb-dark-mode'); }, 3000);

});

function DisableVideo(){
	
	const video = document.querySelectorAll(".opwvks06.hop1g133.linmgsc8.t63ysoy8.qutah8gn.ni8dbmo4.stjgntxs.ktxn16wu.jz9ahs1c.efwgsih4.e72ty7fz.qmr60zad.qlfml3jp.inkptoze").forEach(el => {
        
		el.style.removeProperty("width");
    
	});
	
}

function RemoveSideBar(){
	
	const sidebar = document.querySelector(".rq0escxv.l9j0dhe7.du4w35lb.j83agx80.cbu4d94t.g5gj957u.f4tghd1a.ifue306u.kuivcneq.t63ysoy8");

	sidebar.style.display = "none";
	
}