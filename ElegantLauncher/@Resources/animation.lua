function Initialize()
	count = SKIN:GetVariable('TotalGame')
	skinwidth = tonumber(SKIN:GetVariable('SkinWidth'))
	width = tonumber(SKIN:GetVariable('BannerWidth'))
	height = tonumber(SKIN:GetVariable('BannerHeight'))
	divider=SKIN:GetVariable('ScrollDivider')
	space=tonumber(SKIN:GetVariable('Space'))
	scroll = 0
	select = tonumber(SKIN:GetVariable('Select'))
	show_title =  tonumber(SKIN:GetVariable('Title'))
	loaded = {}
 	w = {}
	x = {}
	meter = {}
	title = {}
	image_w = {}
	image_h = {}
	offsetx=0
	expand=tonumber(SKIN:GetVariable('Expand'))
	swap=0
	scroll_limit=(width*skinwidth+space)*(count-1)-skinwidth+space+(expand*skinwidth)
	local assume=tonumber(SKIN:GetVariable('assume_size'))
	infinite_scroll=tonumber(SKIN:GetVariable('endless_scroll'))
	for i=1, count do
		if i == select then w[i] = (expand*skinwidth) else w[i] = (width*skinwidth) end
		x[i]=(width*skinwidth)*(i-1)
		meter[i] = SKIN:GetMeter("Game" .. i)
		title[i] = SKIN:GetMeter("Title" .. i)
		loaded[i] = 0
	end
end

function assume_image_size(i)
	local h=tonumber(SKIN:GetVariable('CURRENTCONFIGHEIGHT'))
	--for i=1, count do
		image_w[i] = skinwidth
		image_h[i] = h
	--end
end
function get_image_size(i)
	local measure=SKIN:GetMeasure('ImageSize')
	local h=tonumber(SKIN:GetVariable('CURRENTCONFIGHEIGHT'))
	measure:Enable()
	--for i=1, count do
		SKIN:Bang("!SetOption","ImageSize", "ImageName", "#@#Spectrum\\Cover\\#Gamewall".. i .."#")
		SKIN:Bang("!SetOption","ImageSize", "Dimension", "Width")
		SKIN:Bang("!UpdateMeasure","ImageSize")
		image_w[i] = measure:GetValue()
		image_h[i] = h
	--end
	--measure:Disable()
end


function draw_update()
	local xx=offsetx
	local ix=0
	local iw=0
	local ih=0
	for i=1, count do
	if xx>skinwidth*2 then xx=xx-(scroll_limit+skinwidth) end
	if (xx+w[i]>0 and xx<skinwidth) or (x[i]+w[i]>0 and x[i]<skinwidth) then
		meter[i]:Show()
		if loaded[i] == 0 then
			SKIN:Bang("!SetOption","Game"..i, "ImageName", "#@#Spectrum\\Cover\\#Gamewall".. i .."#")
			if assume == 1 then assume_image_size(i) else get_image_size(i) end
			loaded[i] = 1
			end
		if show_title == 1 then title[i]:Show() end
		meter[i]:SetX(xx)
		meter[i]:SetW(w[i])
			SKIN:Bang("!SetOption","Title"..i, "W", w[i]-20)
			title[i]:SetX(xx+20)
		ix=(xx/skinwidth)*image_w[i]
		iw=(w[i]/skinwidth)*image_w[i]
		ih=(image_w[i]/skinwidth)*image_h[i]
		SKIN:Bang("!SetOption","Game" .. i, "ImageCrop", ix .. ',' .. 0 .. ',' .. iw .. ',' .. ih .. ',' .. 1)
	else	meter[i]:Hide()
		title[i]:Hide()
	end
	x[i]=xx
	xx = xx + w[i] + space
	end
	if swap == 1 then
		SKIN:Bang("!SetOption","SwapIcon", "X", offsetx+(select-1)*width*skinwidth)
		SKIN:Bang("!SetOption","SwapIcon", "W", w[select])
	end
end

function animation_update()
	select=tonumber(SKIN:GetVariable('Select'))
	for i=1, count do
		if i == select then
			SKIN:Bang("!SetOption","Game" .. i, "Greyscale", 0)
			else SKIN:Bang("!SetOption","Game" .. i, "Greyscale", 1)
		end
	end
end

function animate()
	local ww
	local div=divider
	offsetx=(offsetx-((offsetx-scroll)/divider))
	for i=1, count do
		if i == select then
			ww = expand*skinwidth
			else ww = width*skinwidth
		end
	w[i]=(w[i]-((w[i]-ww)/div))
	end
	draw_update()
end

function swap_ready()
	swap=1
	for i=1, count do
		SKIN:Bang('!SetOption','Game' .. i, 'LeftMouseUpAction', '[!SetVariable To '..i..'][!UpdateMeasure GameSwap][!CommandMeasure GameSwap "Execute 2"]')
	end
end

function swap_finish()
	swap=0
	for i=1, count do
		SKIN:Bang('!SetOption','Game' .. i, '[!CommandMeasure InputExecute "Execute '..i..'"]')
	end
	image_size()
end


function scroll_list(speed)
	scroll=scroll+(width*skinwidth*speed)
	if infinite_scroll == 1 then infinite_scroll_check() else normal_scroll_check() end
	if scroll == 0 then scroll = 1 end
end

function infinite_scroll_check()
	if scroll<(-scroll_limit+skinwidth) then
		scroll=scroll+scroll_limit+skinwidth
		offsetx=offsetx+scroll_limit+skinwidth
	end
	if scroll>skinwidth then
		scroll=scroll-scroll_limit-skinwidth
		offsetx=offsetx-scroll_limit-skinwidth
	end
end

function normal_scroll_check()
	if scroll>-1 then scroll=-1 end
	if scroll<-scroll_limit then scroll=-scroll_limit end
end
	

function focus()
	local cross=(scroll_limit/(skinwidth*width))+1/width
	select=tonumber(SKIN:GetVariable('Select'))
	local a=-(select-1)*(skinwidth*width+space)+(skinwidth/2)-(expand*skinwidth/2)
	local delta=(a-scroll)/(skinwidth*width)
	if infinite_scroll == 1 then
		if delta < (-cross/2) then delta=delta+cross end
		if delta > (cross/2) then delta=delta-cross end
	end
	scroll_list(delta)
	animation_update()
end

function focus_now()
	local cross=(scroll_limit/(skinwidth*width))+1/width
	select=tonumber(SKIN:GetVariable('Select'))
	local a=-(select-1)*(skinwidth*width+space)+(skinwidth/2)-(expand*skinwidth/2)
	scroll = a 
	offsetx= a
	animation_update()
end