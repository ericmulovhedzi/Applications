function cvr(id,color){document.getElementById(id).style.borderColor = color;}
function bgvr(id,color){document.getElementById(id).style.background = color;}

$(document).ready(function(){

	$("img.opacied").css({"opacity": "1"});
	
	$("img.opacied").hover(function(){$(this).css({'opacity':'0.4'});},function(){$(this).css({'opacity':'1'});});
	
});