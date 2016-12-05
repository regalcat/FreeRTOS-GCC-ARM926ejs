<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<title>Linux/drivers/net/ethernet/smsc/smc91x.h - Linux Cross Reference - Free Electrons</title>
<link rel="stylesheet" href="/style.css" type="text/css" media="screen" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<meta description="Linux Cross-Reference (LXR) service by Free Electrons. The easiest way to study Linux kernel sources. Available for all recent releases." />
<base href="http://lxr.free-electrons.com/"/>
</head>

<body>

<div id="wrapper">
<div id="wrapper2">
<div id="header">

	<div id="logo">
		<h1>Linux Cross Reference</h1>
		<h2><a href="http://free-electrons.com">Free Electrons</a></h2>
		<h2>Embedded Linux Experts</h2>
		<p>
		 &nbsp;&bull;&nbsp;<b><i>source navigation</i></b> &nbsp;&bull;&nbsp;<a href="diff/drivers/net/ethernet/smsc/smc91x.h">diff markup</a> &nbsp;&bull;&nbsp;<a href="ident">identifier search</a> &nbsp;&bull;&nbsp;<a href="search">freetext search</a> &nbsp;&bull;&nbsp;
		</p>
	</div>
</div>

<div id="topbar">
  
  <p>Version: &nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=2.0.40">2.0.40</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=2.2.26">2.2.26</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=2.4.37">2.4.37</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=3.11">3.11</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=3.12">3.12</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=3.13">3.13</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=3.14">3.14</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=3.15">3.15</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=3.16">3.16</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=3.17">3.17</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=3.18">3.18</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=3.19">3.19</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=4.0">4.0</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=4.1">4.1</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=4.2">4.2</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=4.3">4.3</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=4.4">4.4</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=4.5">4.5</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=4.6">4.6</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.h?v=4.7">4.7</a>&nbsp;<b><i>4.8</i></b></p>
  
</div>

<h1><a href="source/">Linux</a>/<a href="source/drivers/">drivers</a>/<a href="source/drivers/net/">net</a>/<a href="source/drivers/net/ethernet/">ethernet</a>/<a href="source/drivers/net/ethernet/smsc/">smsc</a>/<a href="source/drivers/net/ethernet/smsc/smc91x.h">smc91x.h</a></h1>
<div id="lxrcode"><pre>  <a name="L1" href="source/drivers/net/ethernet/smsc/smc91x.h#L1">1</a> <b><i>/*------------------------------------------------------------------------</i></b>
  <a name="L2" href="source/drivers/net/ethernet/smsc/smc91x.h#L2">2</a> <b><i> . smc91x.h - macros for SMSC's 91C9x/91C1xx single-chip Ethernet device.</i></b>
  <a name="L3" href="source/drivers/net/ethernet/smsc/smc91x.h#L3">3</a> <b><i> .</i></b>
  <a name="L4" href="source/drivers/net/ethernet/smsc/smc91x.h#L4">4</a> <b><i> . Copyright (C) 1996 by Erik Stahlman</i></b>
  <a name="L5" href="source/drivers/net/ethernet/smsc/smc91x.h#L5">5</a> <b><i> . Copyright (C) 2001 Standard Microsystems Corporation</i></b>
  <a name="L6" href="source/drivers/net/ethernet/smsc/smc91x.h#L6">6</a> <b><i> .      Developed by Simple Network Magic Corporation</i></b>
  <a name="L7" href="source/drivers/net/ethernet/smsc/smc91x.h#L7">7</a> <b><i> . Copyright (C) 2003 Monta Vista Software, Inc.</i></b>
  <a name="L8" href="source/drivers/net/ethernet/smsc/smc91x.h#L8">8</a> <b><i> .      Unified SMC91x driver by Nicolas Pitre</i></b>
  <a name="L9" href="source/drivers/net/ethernet/smsc/smc91x.h#L9">9</a> <b><i> .</i></b>
 <a name="L10" href="source/drivers/net/ethernet/smsc/smc91x.h#L10">10</a> <b><i> . This program is free software; you can redistribute it and/or modify</i></b>
 <a name="L11" href="source/drivers/net/ethernet/smsc/smc91x.h#L11">11</a> <b><i> . it under the terms of the GNU General Public License as published by</i></b>
 <a name="L12" href="source/drivers/net/ethernet/smsc/smc91x.h#L12">12</a> <b><i> . the Free Software Foundation; either version 2 of the License, or</i></b>
 <a name="L13" href="source/drivers/net/ethernet/smsc/smc91x.h#L13">13</a> <b><i> . (at your option) any later version.</i></b>
 <a name="L14" href="source/drivers/net/ethernet/smsc/smc91x.h#L14">14</a> <b><i> .</i></b>
 <a name="L15" href="source/drivers/net/ethernet/smsc/smc91x.h#L15">15</a> <b><i> . This program is distributed in the hope that it will be useful,</i></b>
 <a name="L16" href="source/drivers/net/ethernet/smsc/smc91x.h#L16">16</a> <b><i> . but WITHOUT ANY WARRANTY; without even the implied warranty of</i></b>
 <a name="L17" href="source/drivers/net/ethernet/smsc/smc91x.h#L17">17</a> <b><i> . MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the</i></b>
 <a name="L18" href="source/drivers/net/ethernet/smsc/smc91x.h#L18">18</a> <b><i> . GNU General Public License for more details.</i></b>
 <a name="L19" href="source/drivers/net/ethernet/smsc/smc91x.h#L19">19</a> <b><i> .</i></b>
 <a name="L20" href="source/drivers/net/ethernet/smsc/smc91x.h#L20">20</a> <b><i> . You should have received a copy of the GNU General Public License</i></b>
 <a name="L21" href="source/drivers/net/ethernet/smsc/smc91x.h#L21">21</a> <b><i> . along with this program; if not, see &lt;<a href="http://www.gnu.org/licenses/&gt;">http://www.gnu.org/licenses/&gt;</a>.</i></b>
 <a name="L22" href="source/drivers/net/ethernet/smsc/smc91x.h#L22">22</a> <b><i> .</i></b>
 <a name="L23" href="source/drivers/net/ethernet/smsc/smc91x.h#L23">23</a> <b><i> . Information contained in this file was obtained from the LAN91C111</i></b>
 <a name="L24" href="source/drivers/net/ethernet/smsc/smc91x.h#L24">24</a> <b><i> . manual from SMC.  To get a copy, if you really want one, you can find</i></b>
 <a name="L25" href="source/drivers/net/ethernet/smsc/smc91x.h#L25">25</a> <b><i> . information under www.smsc.com.</i></b>
 <a name="L26" href="source/drivers/net/ethernet/smsc/smc91x.h#L26">26</a> <b><i> .</i></b>
 <a name="L27" href="source/drivers/net/ethernet/smsc/smc91x.h#L27">27</a> <b><i> . Authors</i></b>
 <a name="L28" href="source/drivers/net/ethernet/smsc/smc91x.h#L28">28</a> <b><i> .      Erik Stahlman           &lt;erik@vt.edu&gt;</i></b>
 <a name="L29" href="source/drivers/net/ethernet/smsc/smc91x.h#L29">29</a> <b><i> .      Daris A Nevil           &lt;dnevil@snmc.com&gt;</i></b>
 <a name="L30" href="source/drivers/net/ethernet/smsc/smc91x.h#L30">30</a> <b><i> .      Nicolas Pitre           &lt;nico@fluxnic.net&gt;</i></b>
 <a name="L31" href="source/drivers/net/ethernet/smsc/smc91x.h#L31">31</a> <b><i> .</i></b>
 <a name="L32" href="source/drivers/net/ethernet/smsc/smc91x.h#L32">32</a> <b><i> ---------------------------------------------------------------------------*/</i></b>
 <a name="L33" href="source/drivers/net/ethernet/smsc/smc91x.h#L33">33</a> #ifndef <a href="ident?i=_SMC91X_H_">_SMC91X_H_</a>
 <a name="L34" href="source/drivers/net/ethernet/smsc/smc91x.h#L34">34</a> #define <a href="ident?i=_SMC91X_H_">_SMC91X_H_</a>
 <a name="L35" href="source/drivers/net/ethernet/smsc/smc91x.h#L35">35</a> 
 <a name="L36" href="source/drivers/net/ethernet/smsc/smc91x.h#L36">36</a> #include &lt;linux/dmaengine.h&gt;
 <a name="L37" href="source/drivers/net/ethernet/smsc/smc91x.h#L37">37</a> #include &lt;linux/smc91x.h&gt;
 <a name="L38" href="source/drivers/net/ethernet/smsc/smc91x.h#L38">38</a> 
 <a name="L39" href="source/drivers/net/ethernet/smsc/smc91x.h#L39">39</a> <b><i>/*</i></b>
 <a name="L40" href="source/drivers/net/ethernet/smsc/smc91x.h#L40">40</a> <b><i> * Any 16-bit access is performed with two 8-bit accesses if the hardware</i></b>
 <a name="L41" href="source/drivers/net/ethernet/smsc/smc91x.h#L41">41</a> <b><i> * can't do it directly. Most registers are 16-bit so those are mandatory.</i></b>
 <a name="L42" href="source/drivers/net/ethernet/smsc/smc91x.h#L42">42</a> <b><i> */</i></b>
 <a name="L43" href="source/drivers/net/ethernet/smsc/smc91x.h#L43">43</a> #define <a href="ident?i=SMC_outw_b">SMC_outw_b</a>(<a href="ident?i=x">x</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)                                             \
 <a name="L44" href="source/drivers/net/ethernet/smsc/smc91x.h#L44">44</a>         do {                                                            \
 <a name="L45" href="source/drivers/net/ethernet/smsc/smc91x.h#L45">45</a>                 unsigned int __val16 = (<a href="ident?i=x">x</a>);                             \
 <a name="L46" href="source/drivers/net/ethernet/smsc/smc91x.h#L46">46</a>                 unsigned int <a href="ident?i=__reg">__reg</a> = (<a href="ident?i=r">r</a>);                               \
 <a name="L47" href="source/drivers/net/ethernet/smsc/smc91x.h#L47">47</a>                 <a href="ident?i=SMC_outb">SMC_outb</a>(__val16, <a href="ident?i=a">a</a>, <a href="ident?i=__reg">__reg</a>);                            \
 <a name="L48" href="source/drivers/net/ethernet/smsc/smc91x.h#L48">48</a>                 <a href="ident?i=SMC_outb">SMC_outb</a>(__val16 &gt;&gt; 8, <a href="ident?i=a">a</a>, <a href="ident?i=__reg">__reg</a> + (1 &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>)); \
 <a name="L49" href="source/drivers/net/ethernet/smsc/smc91x.h#L49">49</a>         } while (0)
 <a name="L50" href="source/drivers/net/ethernet/smsc/smc91x.h#L50">50</a> 
 <a name="L51" href="source/drivers/net/ethernet/smsc/smc91x.h#L51">51</a> #define <a href="ident?i=SMC_inw_b">SMC_inw_b</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)                                                 \
 <a name="L52" href="source/drivers/net/ethernet/smsc/smc91x.h#L52">52</a>         ({                                                              \
 <a name="L53" href="source/drivers/net/ethernet/smsc/smc91x.h#L53">53</a>                 unsigned int __val16;                                   \
 <a name="L54" href="source/drivers/net/ethernet/smsc/smc91x.h#L54">54</a>                 unsigned int <a href="ident?i=__reg">__reg</a> = <a href="ident?i=r">r</a>;                                 \
 <a name="L55" href="source/drivers/net/ethernet/smsc/smc91x.h#L55">55</a>                 __val16  = <a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=__reg">__reg</a>);                           \
 <a name="L56" href="source/drivers/net/ethernet/smsc/smc91x.h#L56">56</a>                 __val16 |= <a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=__reg">__reg</a> + (1 &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>)) &lt;&lt; 8; \
 <a name="L57" href="source/drivers/net/ethernet/smsc/smc91x.h#L57">57</a>                 __val16;                                                \
 <a name="L58" href="source/drivers/net/ethernet/smsc/smc91x.h#L58">58</a>         })
 <a name="L59" href="source/drivers/net/ethernet/smsc/smc91x.h#L59">59</a> 
 <a name="L60" href="source/drivers/net/ethernet/smsc/smc91x.h#L60">60</a> <b><i>/*</i></b>
 <a name="L61" href="source/drivers/net/ethernet/smsc/smc91x.h#L61">61</a> <b><i> * Define your architecture specific bus configuration parameters here.</i></b>
 <a name="L62" href="source/drivers/net/ethernet/smsc/smc91x.h#L62">62</a> <b><i> */</i></b>
 <a name="L63" href="source/drivers/net/ethernet/smsc/smc91x.h#L63">63</a> 
 <a name="L64" href="source/drivers/net/ethernet/smsc/smc91x.h#L64">64</a> #if defined(CONFIG_ARM)
 <a name="L65" href="source/drivers/net/ethernet/smsc/smc91x.h#L65">65</a> 
 <a name="L66" href="source/drivers/net/ethernet/smsc/smc91x.h#L66">66</a> #include &lt;asm/mach-types.h&gt;
 <a name="L67" href="source/drivers/net/ethernet/smsc/smc91x.h#L67">67</a> 
 <a name="L68" href="source/drivers/net/ethernet/smsc/smc91x.h#L68">68</a> <b><i>/* Now the bus width is specified in the platform data</i></b>
 <a name="L69" href="source/drivers/net/ethernet/smsc/smc91x.h#L69">69</a> <b><i> * pretend here to support all I/O access types</i></b>
 <a name="L70" href="source/drivers/net/ethernet/smsc/smc91x.h#L70">70</a> <b><i> */</i></b>
 <a name="L71" href="source/drivers/net/ethernet/smsc/smc91x.h#L71">71</a> #define <a href="ident?i=SMC_CAN_USE_8BIT">SMC_CAN_USE_8BIT</a>        1
 <a name="L72" href="source/drivers/net/ethernet/smsc/smc91x.h#L72">72</a> #define <a href="ident?i=SMC_CAN_USE_16BIT">SMC_CAN_USE_16BIT</a>       1
 <a name="L73" href="source/drivers/net/ethernet/smsc/smc91x.h#L73">73</a> #define <a href="ident?i=SMC_CAN_USE_32BIT">SMC_CAN_USE_32BIT</a>       1
 <a name="L74" href="source/drivers/net/ethernet/smsc/smc91x.h#L74">74</a> #define <a href="ident?i=SMC_NOWAIT">SMC_NOWAIT</a>              1
 <a name="L75" href="source/drivers/net/ethernet/smsc/smc91x.h#L75">75</a> 
 <a name="L76" href="source/drivers/net/ethernet/smsc/smc91x.h#L76">76</a> #define <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>            (<a href="ident?i=lp">lp</a>-&gt;io_shift)
 <a name="L77" href="source/drivers/net/ethernet/smsc/smc91x.h#L77">77</a> 
 <a name="L78" href="source/drivers/net/ethernet/smsc/smc91x.h#L78">78</a> #define <a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=readb">readb</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
 <a name="L79" href="source/drivers/net/ethernet/smsc/smc91x.h#L79">79</a> #define <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)                                                   \
 <a name="L80" href="source/drivers/net/ethernet/smsc/smc91x.h#L80">80</a>         ({                                                              \
 <a name="L81" href="source/drivers/net/ethernet/smsc/smc91x.h#L81">81</a>                 unsigned int __smc_r = <a href="ident?i=r">r</a>;                               \
 <a name="L82" href="source/drivers/net/ethernet/smsc/smc91x.h#L82">82</a>                 <a href="ident?i=SMC_16BIT">SMC_16BIT</a>(<a href="ident?i=lp">lp</a>) ? <a href="ident?i=readw">readw</a>((<a href="ident?i=a">a</a>) + __smc_r) :                  \
 <a name="L83" href="source/drivers/net/ethernet/smsc/smc91x.h#L83">83</a>                 <a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>) ? <a href="ident?i=SMC_inw_b">SMC_inw_b</a>(<a href="ident?i=a">a</a>, __smc_r) :                  \
 <a name="L84" href="source/drivers/net/ethernet/smsc/smc91x.h#L84">84</a>                 ({ <a href="ident?i=BUG">BUG</a>(); 0; });                                        \
 <a name="L85" href="source/drivers/net/ethernet/smsc/smc91x.h#L85">85</a>         })
 <a name="L86" href="source/drivers/net/ethernet/smsc/smc91x.h#L86">86</a> 
 <a name="L87" href="source/drivers/net/ethernet/smsc/smc91x.h#L87">87</a> #define <a href="ident?i=SMC_inl">SMC_inl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=readl">readl</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
 <a name="L88" href="source/drivers/net/ethernet/smsc/smc91x.h#L88">88</a> #define <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=writeb">writeb</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
 <a name="L89" href="source/drivers/net/ethernet/smsc/smc91x.h#L89">89</a> #define <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)                                               \
 <a name="L90" href="source/drivers/net/ethernet/smsc/smc91x.h#L90">90</a>         do {                                                            \
 <a name="L91" href="source/drivers/net/ethernet/smsc/smc91x.h#L91">91</a>                 unsigned int __v = <a href="ident?i=v">v</a>, __smc_r = <a href="ident?i=r">r</a>;                      \
 <a name="L92" href="source/drivers/net/ethernet/smsc/smc91x.h#L92">92</a>                 if (<a href="ident?i=SMC_16BIT">SMC_16BIT</a>(<a href="ident?i=lp">lp</a>))                                      \
 <a name="L93" href="source/drivers/net/ethernet/smsc/smc91x.h#L93">93</a>                         <a href="ident?i=__SMC_outw">__SMC_outw</a>(__v, <a href="ident?i=a">a</a>, __smc_r);                    \
 <a name="L94" href="source/drivers/net/ethernet/smsc/smc91x.h#L94">94</a>                 else if (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>))                                  \
 <a name="L95" href="source/drivers/net/ethernet/smsc/smc91x.h#L95">95</a>                         <a href="ident?i=SMC_outw_b">SMC_outw_b</a>(__v, <a href="ident?i=a">a</a>, __smc_r);                    \
 <a name="L96" href="source/drivers/net/ethernet/smsc/smc91x.h#L96">96</a>                 else                                                    \
 <a name="L97" href="source/drivers/net/ethernet/smsc/smc91x.h#L97">97</a>                         <a href="ident?i=BUG">BUG</a>();                                          \
 <a name="L98" href="source/drivers/net/ethernet/smsc/smc91x.h#L98">98</a>         } while (0)
 <a name="L99" href="source/drivers/net/ethernet/smsc/smc91x.h#L99">99</a> 
<a name="L100" href="source/drivers/net/ethernet/smsc/smc91x.h#L100">100</a> #define <a href="ident?i=SMC_outl">SMC_outl</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=writel">writel</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L101" href="source/drivers/net/ethernet/smsc/smc91x.h#L101">101</a> #define <a href="ident?i=SMC_insb">SMC_insb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=readsb">readsb</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L102" href="source/drivers/net/ethernet/smsc/smc91x.h#L102">102</a> #define <a href="ident?i=SMC_outsb">SMC_outsb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=writesb">writesb</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L103" href="source/drivers/net/ethernet/smsc/smc91x.h#L103">103</a> #define <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=readsw">readsw</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L104" href="source/drivers/net/ethernet/smsc/smc91x.h#L104">104</a> #define <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=writesw">writesw</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L105" href="source/drivers/net/ethernet/smsc/smc91x.h#L105">105</a> #define <a href="ident?i=SMC_insl">SMC_insl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=readsl">readsl</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L106" href="source/drivers/net/ethernet/smsc/smc91x.h#L106">106</a> #define <a href="ident?i=SMC_outsl">SMC_outsl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=writesl">writesl</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L107" href="source/drivers/net/ethernet/smsc/smc91x.h#L107">107</a> #define <a href="ident?i=SMC_IRQ_FLAGS">SMC_IRQ_FLAGS</a>           (-1)    <b><i>/* from resource */</i></b>
<a name="L108" href="source/drivers/net/ethernet/smsc/smc91x.h#L108">108</a> 
<a name="L109" href="source/drivers/net/ethernet/smsc/smc91x.h#L109">109</a> <b><i>/* We actually can't write halfwords properly if not word aligned */</i></b>
<a name="L110" href="source/drivers/net/ethernet/smsc/smc91x.h#L110">110</a> static inline void <a href="ident?i=__SMC_outw">__SMC_outw</a>(<a href="ident?i=u16">u16</a> <a href="ident?i=val">val</a>, void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a>, int <a href="ident?i=reg">reg</a>)
<a name="L111" href="source/drivers/net/ethernet/smsc/smc91x.h#L111">111</a> {
<a name="L112" href="source/drivers/net/ethernet/smsc/smc91x.h#L112">112</a>         if ((machine_is_mainstone() || machine_is_stargate2() ||
<a name="L113" href="source/drivers/net/ethernet/smsc/smc91x.h#L113">113</a>              machine_is_pxa_idp()) &amp;&amp; <a href="ident?i=reg">reg</a> &amp; 2) {
<a name="L114" href="source/drivers/net/ethernet/smsc/smc91x.h#L114">114</a>                 unsigned int <a href="ident?i=v">v</a> = <a href="ident?i=val">val</a> &lt;&lt; 16;
<a name="L115" href="source/drivers/net/ethernet/smsc/smc91x.h#L115">115</a>                 <a href="ident?i=v">v</a> |= <a href="ident?i=readl">readl</a>(<a href="ident?i=ioaddr">ioaddr</a> + (<a href="ident?i=reg">reg</a> &amp; ~2)) &amp; 0xffff;
<a name="L116" href="source/drivers/net/ethernet/smsc/smc91x.h#L116">116</a>                 <a href="ident?i=writel">writel</a>(<a href="ident?i=v">v</a>, <a href="ident?i=ioaddr">ioaddr</a> + (<a href="ident?i=reg">reg</a> &amp; ~2));
<a name="L117" href="source/drivers/net/ethernet/smsc/smc91x.h#L117">117</a>         } else {
<a name="L118" href="source/drivers/net/ethernet/smsc/smc91x.h#L118">118</a>                 <a href="ident?i=writew">writew</a>(<a href="ident?i=val">val</a>, <a href="ident?i=ioaddr">ioaddr</a> + <a href="ident?i=reg">reg</a>);
<a name="L119" href="source/drivers/net/ethernet/smsc/smc91x.h#L119">119</a>         }
<a name="L120" href="source/drivers/net/ethernet/smsc/smc91x.h#L120">120</a> }
<a name="L121" href="source/drivers/net/ethernet/smsc/smc91x.h#L121">121</a> 
<a name="L122" href="source/drivers/net/ethernet/smsc/smc91x.h#L122">122</a> #elif   defined(CONFIG_SH_SH4202_MICRODEV)
<a name="L123" href="source/drivers/net/ethernet/smsc/smc91x.h#L123">123</a> 
<a name="L124" href="source/drivers/net/ethernet/smsc/smc91x.h#L124">124</a> #define <a href="ident?i=SMC_CAN_USE_8BIT">SMC_CAN_USE_8BIT</a>        0
<a name="L125" href="source/drivers/net/ethernet/smsc/smc91x.h#L125">125</a> #define <a href="ident?i=SMC_CAN_USE_16BIT">SMC_CAN_USE_16BIT</a>       1
<a name="L126" href="source/drivers/net/ethernet/smsc/smc91x.h#L126">126</a> #define <a href="ident?i=SMC_CAN_USE_32BIT">SMC_CAN_USE_32BIT</a>       0
<a name="L127" href="source/drivers/net/ethernet/smsc/smc91x.h#L127">127</a> 
<a name="L128" href="source/drivers/net/ethernet/smsc/smc91x.h#L128">128</a> #define <a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=inb">inb</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000)
<a name="L129" href="source/drivers/net/ethernet/smsc/smc91x.h#L129">129</a> #define <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=inw">inw</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000)
<a name="L130" href="source/drivers/net/ethernet/smsc/smc91x.h#L130">130</a> #define <a href="ident?i=SMC_inl">SMC_inl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=inl">inl</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000)
<a name="L131" href="source/drivers/net/ethernet/smsc/smc91x.h#L131">131</a> #define <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=outb">outb</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000)
<a name="L132" href="source/drivers/net/ethernet/smsc/smc91x.h#L132">132</a> #define <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=outw">outw</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000)
<a name="L133" href="source/drivers/net/ethernet/smsc/smc91x.h#L133">133</a> #define <a href="ident?i=SMC_outl">SMC_outl</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=outl">outl</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000)
<a name="L134" href="source/drivers/net/ethernet/smsc/smc91x.h#L134">134</a> #define <a href="ident?i=SMC_insl">SMC_insl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=insl">insl</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L135" href="source/drivers/net/ethernet/smsc/smc91x.h#L135">135</a> #define <a href="ident?i=SMC_outsl">SMC_outsl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=outsl">outsl</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L136" href="source/drivers/net/ethernet/smsc/smc91x.h#L136">136</a> #define <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=insw">insw</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L137" href="source/drivers/net/ethernet/smsc/smc91x.h#L137">137</a> #define <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=outsw">outsw</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>) - 0xa0000000, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L138" href="source/drivers/net/ethernet/smsc/smc91x.h#L138">138</a> 
<a name="L139" href="source/drivers/net/ethernet/smsc/smc91x.h#L139">139</a> #define <a href="ident?i=SMC_IRQ_FLAGS">SMC_IRQ_FLAGS</a>           (0)
<a name="L140" href="source/drivers/net/ethernet/smsc/smc91x.h#L140">140</a> 
<a name="L141" href="source/drivers/net/ethernet/smsc/smc91x.h#L141">141</a> #elif   defined(CONFIG_M32R)
<a name="L142" href="source/drivers/net/ethernet/smsc/smc91x.h#L142">142</a> 
<a name="L143" href="source/drivers/net/ethernet/smsc/smc91x.h#L143">143</a> #define <a href="ident?i=SMC_CAN_USE_8BIT">SMC_CAN_USE_8BIT</a>        0
<a name="L144" href="source/drivers/net/ethernet/smsc/smc91x.h#L144">144</a> #define <a href="ident?i=SMC_CAN_USE_16BIT">SMC_CAN_USE_16BIT</a>       1
<a name="L145" href="source/drivers/net/ethernet/smsc/smc91x.h#L145">145</a> #define <a href="ident?i=SMC_CAN_USE_32BIT">SMC_CAN_USE_32BIT</a>       0
<a name="L146" href="source/drivers/net/ethernet/smsc/smc91x.h#L146">146</a> 
<a name="L147" href="source/drivers/net/ethernet/smsc/smc91x.h#L147">147</a> #define <a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=inb">inb</a>(((<a href="ident?i=u32">u32</a>)<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L148" href="source/drivers/net/ethernet/smsc/smc91x.h#L148">148</a> #define <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=inw">inw</a>(((<a href="ident?i=u32">u32</a>)<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L149" href="source/drivers/net/ethernet/smsc/smc91x.h#L149">149</a> #define <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=outb">outb</a>(<a href="ident?i=v">v</a>, ((<a href="ident?i=u32">u32</a>)<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L150" href="source/drivers/net/ethernet/smsc/smc91x.h#L150">150</a> #define <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=outw">outw</a>(<a href="ident?i=v">v</a>, ((<a href="ident?i=u32">u32</a>)<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L151" href="source/drivers/net/ethernet/smsc/smc91x.h#L151">151</a> #define <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=insw">insw</a>(((<a href="ident?i=u32">u32</a>)<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L152" href="source/drivers/net/ethernet/smsc/smc91x.h#L152">152</a> #define <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=outsw">outsw</a>(((<a href="ident?i=u32">u32</a>)<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L153" href="source/drivers/net/ethernet/smsc/smc91x.h#L153">153</a> 
<a name="L154" href="source/drivers/net/ethernet/smsc/smc91x.h#L154">154</a> #define <a href="ident?i=SMC_IRQ_FLAGS">SMC_IRQ_FLAGS</a>           (0)
<a name="L155" href="source/drivers/net/ethernet/smsc/smc91x.h#L155">155</a> 
<a name="L156" href="source/drivers/net/ethernet/smsc/smc91x.h#L156">156</a> #define <a href="ident?i=RPC_LSA_DEFAULT">RPC_LSA_DEFAULT</a>         <a href="ident?i=RPC_LED_TX_RX">RPC_LED_TX_RX</a>
<a name="L157" href="source/drivers/net/ethernet/smsc/smc91x.h#L157">157</a> #define <a href="ident?i=RPC_LSB_DEFAULT">RPC_LSB_DEFAULT</a>         <a href="ident?i=RPC_LED_100_10">RPC_LED_100_10</a>
<a name="L158" href="source/drivers/net/ethernet/smsc/smc91x.h#L158">158</a> 
<a name="L159" href="source/drivers/net/ethernet/smsc/smc91x.h#L159">159</a> #elif defined(CONFIG_MN10300)
<a name="L160" href="source/drivers/net/ethernet/smsc/smc91x.h#L160">160</a> 
<a name="L161" href="source/drivers/net/ethernet/smsc/smc91x.h#L161">161</a> <b><i>/*</i></b>
<a name="L162" href="source/drivers/net/ethernet/smsc/smc91x.h#L162">162</a> <b><i> * MN10300/AM33 configuration</i></b>
<a name="L163" href="source/drivers/net/ethernet/smsc/smc91x.h#L163">163</a> <b><i> */</i></b>
<a name="L164" href="source/drivers/net/ethernet/smsc/smc91x.h#L164">164</a> 
<a name="L165" href="source/drivers/net/ethernet/smsc/smc91x.h#L165">165</a> #include &lt;unit/smc91111.h&gt;
<a name="L166" href="source/drivers/net/ethernet/smsc/smc91x.h#L166">166</a> 
<a name="L167" href="source/drivers/net/ethernet/smsc/smc91x.h#L167">167</a> #elif defined(CONFIG_ATARI)
<a name="L168" href="source/drivers/net/ethernet/smsc/smc91x.h#L168">168</a> 
<a name="L169" href="source/drivers/net/ethernet/smsc/smc91x.h#L169">169</a> #define <a href="ident?i=SMC_CAN_USE_8BIT">SMC_CAN_USE_8BIT</a>        1
<a name="L170" href="source/drivers/net/ethernet/smsc/smc91x.h#L170">170</a> #define <a href="ident?i=SMC_CAN_USE_16BIT">SMC_CAN_USE_16BIT</a>       1
<a name="L171" href="source/drivers/net/ethernet/smsc/smc91x.h#L171">171</a> #define <a href="ident?i=SMC_CAN_USE_32BIT">SMC_CAN_USE_32BIT</a>       1
<a name="L172" href="source/drivers/net/ethernet/smsc/smc91x.h#L172">172</a> #define <a href="ident?i=SMC_NOWAIT">SMC_NOWAIT</a>              1
<a name="L173" href="source/drivers/net/ethernet/smsc/smc91x.h#L173">173</a> 
<a name="L174" href="source/drivers/net/ethernet/smsc/smc91x.h#L174">174</a> #define <a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=readb">readb</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L175" href="source/drivers/net/ethernet/smsc/smc91x.h#L175">175</a> #define <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=readw">readw</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L176" href="source/drivers/net/ethernet/smsc/smc91x.h#L176">176</a> #define <a href="ident?i=SMC_inl">SMC_inl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=readl">readl</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L177" href="source/drivers/net/ethernet/smsc/smc91x.h#L177">177</a> #define <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=writeb">writeb</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L178" href="source/drivers/net/ethernet/smsc/smc91x.h#L178">178</a> #define <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=writew">writew</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L179" href="source/drivers/net/ethernet/smsc/smc91x.h#L179">179</a> #define <a href="ident?i=SMC_outl">SMC_outl</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=writel">writel</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L180" href="source/drivers/net/ethernet/smsc/smc91x.h#L180">180</a> #define <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=readsw">readsw</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L181" href="source/drivers/net/ethernet/smsc/smc91x.h#L181">181</a> #define <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=writesw">writesw</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L182" href="source/drivers/net/ethernet/smsc/smc91x.h#L182">182</a> #define <a href="ident?i=SMC_insl">SMC_insl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=readsl">readsl</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L183" href="source/drivers/net/ethernet/smsc/smc91x.h#L183">183</a> #define <a href="ident?i=SMC_outsl">SMC_outsl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=writesl">writesl</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L184" href="source/drivers/net/ethernet/smsc/smc91x.h#L184">184</a> 
<a name="L185" href="source/drivers/net/ethernet/smsc/smc91x.h#L185">185</a> #define <a href="ident?i=RPC_LSA_DEFAULT">RPC_LSA_DEFAULT</a>         <a href="ident?i=RPC_LED_100_10">RPC_LED_100_10</a>
<a name="L186" href="source/drivers/net/ethernet/smsc/smc91x.h#L186">186</a> #define <a href="ident?i=RPC_LSB_DEFAULT">RPC_LSB_DEFAULT</a>         <a href="ident?i=RPC_LED_TX_RX">RPC_LED_TX_RX</a>
<a name="L187" href="source/drivers/net/ethernet/smsc/smc91x.h#L187">187</a> 
<a name="L188" href="source/drivers/net/ethernet/smsc/smc91x.h#L188">188</a> #elif defined(CONFIG_COLDFIRE)
<a name="L189" href="source/drivers/net/ethernet/smsc/smc91x.h#L189">189</a> 
<a name="L190" href="source/drivers/net/ethernet/smsc/smc91x.h#L190">190</a> #define <a href="ident?i=SMC_CAN_USE_8BIT">SMC_CAN_USE_8BIT</a>        0
<a name="L191" href="source/drivers/net/ethernet/smsc/smc91x.h#L191">191</a> #define <a href="ident?i=SMC_CAN_USE_16BIT">SMC_CAN_USE_16BIT</a>       1
<a name="L192" href="source/drivers/net/ethernet/smsc/smc91x.h#L192">192</a> #define <a href="ident?i=SMC_CAN_USE_32BIT">SMC_CAN_USE_32BIT</a>       0
<a name="L193" href="source/drivers/net/ethernet/smsc/smc91x.h#L193">193</a> #define <a href="ident?i=SMC_NOWAIT">SMC_NOWAIT</a>              1
<a name="L194" href="source/drivers/net/ethernet/smsc/smc91x.h#L194">194</a> 
<a name="L195" href="source/drivers/net/ethernet/smsc/smc91x.h#L195">195</a> static inline void <a href="ident?i=mcf_insw">mcf_insw</a>(void *<a href="ident?i=a">a</a>, unsigned char *<a href="ident?i=p">p</a>, int <a href="ident?i=l">l</a>)
<a name="L196" href="source/drivers/net/ethernet/smsc/smc91x.h#L196">196</a> {
<a name="L197" href="source/drivers/net/ethernet/smsc/smc91x.h#L197">197</a>         <a href="ident?i=u16">u16</a> *<a href="ident?i=wp">wp</a> = (<a href="ident?i=u16">u16</a> *) <a href="ident?i=p">p</a>;
<a name="L198" href="source/drivers/net/ethernet/smsc/smc91x.h#L198">198</a>         while (<a href="ident?i=l">l</a>-- &gt; 0)
<a name="L199" href="source/drivers/net/ethernet/smsc/smc91x.h#L199">199</a>                 *<a href="ident?i=wp">wp</a>++ = <a href="ident?i=readw">readw</a>(<a href="ident?i=a">a</a>);
<a name="L200" href="source/drivers/net/ethernet/smsc/smc91x.h#L200">200</a> }
<a name="L201" href="source/drivers/net/ethernet/smsc/smc91x.h#L201">201</a> 
<a name="L202" href="source/drivers/net/ethernet/smsc/smc91x.h#L202">202</a> static inline void <a href="ident?i=mcf_outsw">mcf_outsw</a>(void *<a href="ident?i=a">a</a>, unsigned char *<a href="ident?i=p">p</a>, int <a href="ident?i=l">l</a>)
<a name="L203" href="source/drivers/net/ethernet/smsc/smc91x.h#L203">203</a> {
<a name="L204" href="source/drivers/net/ethernet/smsc/smc91x.h#L204">204</a>         <a href="ident?i=u16">u16</a> *<a href="ident?i=wp">wp</a> = (<a href="ident?i=u16">u16</a> *) <a href="ident?i=p">p</a>;
<a name="L205" href="source/drivers/net/ethernet/smsc/smc91x.h#L205">205</a>         while (<a href="ident?i=l">l</a>-- &gt; 0)
<a name="L206" href="source/drivers/net/ethernet/smsc/smc91x.h#L206">206</a>                 <a href="ident?i=writew">writew</a>(*<a href="ident?i=wp">wp</a>++, <a href="ident?i=a">a</a>);
<a name="L207" href="source/drivers/net/ethernet/smsc/smc91x.h#L207">207</a> }
<a name="L208" href="source/drivers/net/ethernet/smsc/smc91x.h#L208">208</a> 
<a name="L209" href="source/drivers/net/ethernet/smsc/smc91x.h#L209">209</a> #define <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=_swapw">_swapw</a>(<a href="ident?i=readw">readw</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>)))
<a name="L210" href="source/drivers/net/ethernet/smsc/smc91x.h#L210">210</a> #define <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=writew">writew</a>(<a href="ident?i=_swapw">_swapw</a>(<a href="ident?i=v">v</a>), (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L211" href="source/drivers/net/ethernet/smsc/smc91x.h#L211">211</a> #define <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=mcf_insw">mcf_insw</a>(<a href="ident?i=a">a</a> + <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L212" href="source/drivers/net/ethernet/smsc/smc91x.h#L212">212</a> #define <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=mcf_outsw">mcf_outsw</a>(<a href="ident?i=a">a</a> + <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L213" href="source/drivers/net/ethernet/smsc/smc91x.h#L213">213</a> 
<a name="L214" href="source/drivers/net/ethernet/smsc/smc91x.h#L214">214</a> #define <a href="ident?i=SMC_IRQ_FLAGS">SMC_IRQ_FLAGS</a>           0
<a name="L215" href="source/drivers/net/ethernet/smsc/smc91x.h#L215">215</a> 
<a name="L216" href="source/drivers/net/ethernet/smsc/smc91x.h#L216">216</a> #elif defined(CONFIG_H8300)
<a name="L217" href="source/drivers/net/ethernet/smsc/smc91x.h#L217">217</a> #define <a href="ident?i=SMC_CAN_USE_8BIT">SMC_CAN_USE_8BIT</a>        1
<a name="L218" href="source/drivers/net/ethernet/smsc/smc91x.h#L218">218</a> #define <a href="ident?i=SMC_CAN_USE_16BIT">SMC_CAN_USE_16BIT</a>       0
<a name="L219" href="source/drivers/net/ethernet/smsc/smc91x.h#L219">219</a> #define <a href="ident?i=SMC_CAN_USE_32BIT">SMC_CAN_USE_32BIT</a>       0
<a name="L220" href="source/drivers/net/ethernet/smsc/smc91x.h#L220">220</a> #define <a href="ident?i=SMC_NOWAIT">SMC_NOWAIT</a>              0
<a name="L221" href="source/drivers/net/ethernet/smsc/smc91x.h#L221">221</a> 
<a name="L222" href="source/drivers/net/ethernet/smsc/smc91x.h#L222">222</a> #define <a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=ioread8">ioread8</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L223" href="source/drivers/net/ethernet/smsc/smc91x.h#L223">223</a> #define <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=iowrite8">iowrite8</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L224" href="source/drivers/net/ethernet/smsc/smc91x.h#L224">224</a> #define <a href="ident?i=SMC_insb">SMC_insb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=ioread8_rep">ioread8_rep</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L225" href="source/drivers/net/ethernet/smsc/smc91x.h#L225">225</a> #define <a href="ident?i=SMC_outsb">SMC_outsb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=iowrite8_rep">iowrite8_rep</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L226" href="source/drivers/net/ethernet/smsc/smc91x.h#L226">226</a> 
<a name="L227" href="source/drivers/net/ethernet/smsc/smc91x.h#L227">227</a> #else
<a name="L228" href="source/drivers/net/ethernet/smsc/smc91x.h#L228">228</a> 
<a name="L229" href="source/drivers/net/ethernet/smsc/smc91x.h#L229">229</a> <b><i>/*</i></b>
<a name="L230" href="source/drivers/net/ethernet/smsc/smc91x.h#L230">230</a> <b><i> * Default configuration</i></b>
<a name="L231" href="source/drivers/net/ethernet/smsc/smc91x.h#L231">231</a> <b><i> */</i></b>
<a name="L232" href="source/drivers/net/ethernet/smsc/smc91x.h#L232">232</a> 
<a name="L233" href="source/drivers/net/ethernet/smsc/smc91x.h#L233">233</a> #define <a href="ident?i=SMC_CAN_USE_8BIT">SMC_CAN_USE_8BIT</a>        1
<a name="L234" href="source/drivers/net/ethernet/smsc/smc91x.h#L234">234</a> #define <a href="ident?i=SMC_CAN_USE_16BIT">SMC_CAN_USE_16BIT</a>       1
<a name="L235" href="source/drivers/net/ethernet/smsc/smc91x.h#L235">235</a> #define <a href="ident?i=SMC_CAN_USE_32BIT">SMC_CAN_USE_32BIT</a>       1
<a name="L236" href="source/drivers/net/ethernet/smsc/smc91x.h#L236">236</a> #define <a href="ident?i=SMC_NOWAIT">SMC_NOWAIT</a>              1
<a name="L237" href="source/drivers/net/ethernet/smsc/smc91x.h#L237">237</a> 
<a name="L238" href="source/drivers/net/ethernet/smsc/smc91x.h#L238">238</a> #define <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>            (<a href="ident?i=lp">lp</a>-&gt;io_shift)
<a name="L239" href="source/drivers/net/ethernet/smsc/smc91x.h#L239">239</a> 
<a name="L240" href="source/drivers/net/ethernet/smsc/smc91x.h#L240">240</a> #define <a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=ioread8">ioread8</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L241" href="source/drivers/net/ethernet/smsc/smc91x.h#L241">241</a> #define <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=ioread16">ioread16</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L242" href="source/drivers/net/ethernet/smsc/smc91x.h#L242">242</a> #define <a href="ident?i=SMC_inl">SMC_inl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)           <a href="ident?i=ioread32">ioread32</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L243" href="source/drivers/net/ethernet/smsc/smc91x.h#L243">243</a> #define <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=iowrite8">iowrite8</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L244" href="source/drivers/net/ethernet/smsc/smc91x.h#L244">244</a> #define <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=iowrite16">iowrite16</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L245" href="source/drivers/net/ethernet/smsc/smc91x.h#L245">245</a> #define <a href="ident?i=SMC_outl">SMC_outl</a>(<a href="ident?i=v">v</a>, <a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>)       <a href="ident?i=iowrite32">iowrite32</a>(<a href="ident?i=v">v</a>, (<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>))
<a name="L246" href="source/drivers/net/ethernet/smsc/smc91x.h#L246">246</a> #define <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=ioread16_rep">ioread16_rep</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L247" href="source/drivers/net/ethernet/smsc/smc91x.h#L247">247</a> #define <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=iowrite16_rep">iowrite16_rep</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L248" href="source/drivers/net/ethernet/smsc/smc91x.h#L248">248</a> #define <a href="ident?i=SMC_insl">SMC_insl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)    <a href="ident?i=ioread32_rep">ioread32_rep</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L249" href="source/drivers/net/ethernet/smsc/smc91x.h#L249">249</a> #define <a href="ident?i=SMC_outsl">SMC_outsl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)   <a href="ident?i=iowrite32_rep">iowrite32_rep</a>((<a href="ident?i=a">a</a>) + (<a href="ident?i=r">r</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L250" href="source/drivers/net/ethernet/smsc/smc91x.h#L250">250</a> 
<a name="L251" href="source/drivers/net/ethernet/smsc/smc91x.h#L251">251</a> #define <a href="ident?i=RPC_LSA_DEFAULT">RPC_LSA_DEFAULT</a>         <a href="ident?i=RPC_LED_100_10">RPC_LED_100_10</a>
<a name="L252" href="source/drivers/net/ethernet/smsc/smc91x.h#L252">252</a> #define <a href="ident?i=RPC_LSB_DEFAULT">RPC_LSB_DEFAULT</a>         <a href="ident?i=RPC_LED_TX_RX">RPC_LED_TX_RX</a>
<a name="L253" href="source/drivers/net/ethernet/smsc/smc91x.h#L253">253</a> 
<a name="L254" href="source/drivers/net/ethernet/smsc/smc91x.h#L254">254</a> #endif
<a name="L255" href="source/drivers/net/ethernet/smsc/smc91x.h#L255">255</a> 
<a name="L256" href="source/drivers/net/ethernet/smsc/smc91x.h#L256">256</a> 
<a name="L257" href="source/drivers/net/ethernet/smsc/smc91x.h#L257">257</a> <b><i>/* store this information for the driver.. */</i></b>
<a name="L258" href="source/drivers/net/ethernet/smsc/smc91x.h#L258">258</a> struct <a href="ident?i=smc_local">smc_local</a> {
<a name="L259" href="source/drivers/net/ethernet/smsc/smc91x.h#L259">259</a>         <b><i>/*</i></b>
<a name="L260" href="source/drivers/net/ethernet/smsc/smc91x.h#L260">260</a> <b><i>         * If I have to wait until memory is available to send a</i></b>
<a name="L261" href="source/drivers/net/ethernet/smsc/smc91x.h#L261">261</a> <b><i>         * packet, I will store the skbuff here, until I get the</i></b>
<a name="L262" href="source/drivers/net/ethernet/smsc/smc91x.h#L262">262</a> <b><i>         * desired memory.  Then, I'll send it out and free it.</i></b>
<a name="L263" href="source/drivers/net/ethernet/smsc/smc91x.h#L263">263</a> <b><i>         */</i></b>
<a name="L264" href="source/drivers/net/ethernet/smsc/smc91x.h#L264">264</a>         struct <a href="ident?i=sk_buff">sk_buff</a> *pending_tx_skb;
<a name="L265" href="source/drivers/net/ethernet/smsc/smc91x.h#L265">265</a>         struct <a href="ident?i=tasklet_struct">tasklet_struct</a> tx_task;
<a name="L266" href="source/drivers/net/ethernet/smsc/smc91x.h#L266">266</a> 
<a name="L267" href="source/drivers/net/ethernet/smsc/smc91x.h#L267">267</a>         struct <a href="ident?i=gpio_desc">gpio_desc</a> *power_gpio;
<a name="L268" href="source/drivers/net/ethernet/smsc/smc91x.h#L268">268</a>         struct <a href="ident?i=gpio_desc">gpio_desc</a> *<a href="ident?i=reset_gpio">reset_gpio</a>;
<a name="L269" href="source/drivers/net/ethernet/smsc/smc91x.h#L269">269</a> 
<a name="L270" href="source/drivers/net/ethernet/smsc/smc91x.h#L270">270</a>         <b><i>/* version/revision of the SMC91x chip */</i></b>
<a name="L271" href="source/drivers/net/ethernet/smsc/smc91x.h#L271">271</a>         int     <a href="ident?i=version">version</a>;
<a name="L272" href="source/drivers/net/ethernet/smsc/smc91x.h#L272">272</a> 
<a name="L273" href="source/drivers/net/ethernet/smsc/smc91x.h#L273">273</a>         <b><i>/* Contains the current active transmission mode */</i></b>
<a name="L274" href="source/drivers/net/ethernet/smsc/smc91x.h#L274">274</a>         int     tcr_cur_mode;
<a name="L275" href="source/drivers/net/ethernet/smsc/smc91x.h#L275">275</a> 
<a name="L276" href="source/drivers/net/ethernet/smsc/smc91x.h#L276">276</a>         <b><i>/* Contains the current active receive mode */</i></b>
<a name="L277" href="source/drivers/net/ethernet/smsc/smc91x.h#L277">277</a>         int     rcr_cur_mode;
<a name="L278" href="source/drivers/net/ethernet/smsc/smc91x.h#L278">278</a> 
<a name="L279" href="source/drivers/net/ethernet/smsc/smc91x.h#L279">279</a>         <b><i>/* Contains the current active receive/phy mode */</i></b>
<a name="L280" href="source/drivers/net/ethernet/smsc/smc91x.h#L280">280</a>         int     rpc_cur_mode;
<a name="L281" href="source/drivers/net/ethernet/smsc/smc91x.h#L281">281</a>         int     ctl_rfduplx;
<a name="L282" href="source/drivers/net/ethernet/smsc/smc91x.h#L282">282</a>         int     ctl_rspeed;
<a name="L283" href="source/drivers/net/ethernet/smsc/smc91x.h#L283">283</a> 
<a name="L284" href="source/drivers/net/ethernet/smsc/smc91x.h#L284">284</a>         <a href="ident?i=u32">u32</a>     <a href="ident?i=msg_enable">msg_enable</a>;
<a name="L285" href="source/drivers/net/ethernet/smsc/smc91x.h#L285">285</a>         <a href="ident?i=u32">u32</a>     phy_type;
<a name="L286" href="source/drivers/net/ethernet/smsc/smc91x.h#L286">286</a>         struct <a href="ident?i=mii_if_info">mii_if_info</a> mii;
<a name="L287" href="source/drivers/net/ethernet/smsc/smc91x.h#L287">287</a> 
<a name="L288" href="source/drivers/net/ethernet/smsc/smc91x.h#L288">288</a>         <b><i>/* work queue */</i></b>
<a name="L289" href="source/drivers/net/ethernet/smsc/smc91x.h#L289">289</a>         struct <a href="ident?i=work_struct">work_struct</a> phy_configure;
<a name="L290" href="source/drivers/net/ethernet/smsc/smc91x.h#L290">290</a>         struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>;
<a name="L291" href="source/drivers/net/ethernet/smsc/smc91x.h#L291">291</a>         int     <a href="ident?i=work_pending">work_pending</a>;
<a name="L292" href="source/drivers/net/ethernet/smsc/smc91x.h#L292">292</a> 
<a name="L293" href="source/drivers/net/ethernet/smsc/smc91x.h#L293">293</a>         <a href="ident?i=spinlock_t">spinlock_t</a> <a href="ident?i=lock">lock</a>;
<a name="L294" href="source/drivers/net/ethernet/smsc/smc91x.h#L294">294</a> 
<a name="L295" href="source/drivers/net/ethernet/smsc/smc91x.h#L295">295</a> #ifdef CONFIG_ARCH_PXA
<a name="L296" href="source/drivers/net/ethernet/smsc/smc91x.h#L296">296</a>         <b><i>/* DMA needs the physical address of the chip */</i></b>
<a name="L297" href="source/drivers/net/ethernet/smsc/smc91x.h#L297">297</a>         <a href="ident?i=u_long">u_long</a> <a href="ident?i=physaddr">physaddr</a>;
<a name="L298" href="source/drivers/net/ethernet/smsc/smc91x.h#L298">298</a>         struct <a href="ident?i=device">device</a> *<a href="ident?i=device">device</a>;
<a name="L299" href="source/drivers/net/ethernet/smsc/smc91x.h#L299">299</a> #endif
<a name="L300" href="source/drivers/net/ethernet/smsc/smc91x.h#L300">300</a>         struct <a href="ident?i=dma_chan">dma_chan</a> *<a href="ident?i=dma_chan">dma_chan</a>;
<a name="L301" href="source/drivers/net/ethernet/smsc/smc91x.h#L301">301</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=base">base</a>;
<a name="L302" href="source/drivers/net/ethernet/smsc/smc91x.h#L302">302</a>         void <a href="ident?i=__iomem">__iomem</a> *datacs;
<a name="L303" href="source/drivers/net/ethernet/smsc/smc91x.h#L303">303</a> 
<a name="L304" href="source/drivers/net/ethernet/smsc/smc91x.h#L304">304</a>         <b><i>/* the low address lines on some platforms aren't connected... */</i></b>
<a name="L305" href="source/drivers/net/ethernet/smsc/smc91x.h#L305">305</a>         int     io_shift;
<a name="L306" href="source/drivers/net/ethernet/smsc/smc91x.h#L306">306</a> 
<a name="L307" href="source/drivers/net/ethernet/smsc/smc91x.h#L307">307</a>         struct <a href="ident?i=smc91x_platdata">smc91x_platdata</a> <a href="ident?i=cfg">cfg</a>;
<a name="L308" href="source/drivers/net/ethernet/smsc/smc91x.h#L308">308</a> };
<a name="L309" href="source/drivers/net/ethernet/smsc/smc91x.h#L309">309</a> 
<a name="L310" href="source/drivers/net/ethernet/smsc/smc91x.h#L310">310</a> #define <a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=p">p</a>)     ((<a href="ident?i=p">p</a>)-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=SMC91X_USE_8BIT">SMC91X_USE_8BIT</a>)
<a name="L311" href="source/drivers/net/ethernet/smsc/smc91x.h#L311">311</a> #define <a href="ident?i=SMC_16BIT">SMC_16BIT</a>(<a href="ident?i=p">p</a>)    ((<a href="ident?i=p">p</a>)-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=SMC91X_USE_16BIT">SMC91X_USE_16BIT</a>)
<a name="L312" href="source/drivers/net/ethernet/smsc/smc91x.h#L312">312</a> #define <a href="ident?i=SMC_32BIT">SMC_32BIT</a>(<a href="ident?i=p">p</a>)    ((<a href="ident?i=p">p</a>)-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=SMC91X_USE_32BIT">SMC91X_USE_32BIT</a>)
<a name="L313" href="source/drivers/net/ethernet/smsc/smc91x.h#L313">313</a> 
<a name="L314" href="source/drivers/net/ethernet/smsc/smc91x.h#L314">314</a> #ifdef CONFIG_ARCH_PXA
<a name="L315" href="source/drivers/net/ethernet/smsc/smc91x.h#L315">315</a> <b><i>/*</i></b>
<a name="L316" href="source/drivers/net/ethernet/smsc/smc91x.h#L316">316</a> <b><i> * Let's use the DMA engine on the XScale PXA2xx for RX packets. This is</i></b>
<a name="L317" href="source/drivers/net/ethernet/smsc/smc91x.h#L317">317</a> <b><i> * always happening in irq context so no need to worry about races.  TX is</i></b>
<a name="L318" href="source/drivers/net/ethernet/smsc/smc91x.h#L318">318</a> <b><i> * different and probably not worth it for that reason, and not as critical</i></b>
<a name="L319" href="source/drivers/net/ethernet/smsc/smc91x.h#L319">319</a> <b><i> * as RX which can overrun memory and lose packets.</i></b>
<a name="L320" href="source/drivers/net/ethernet/smsc/smc91x.h#L320">320</a> <b><i> */</i></b>
<a name="L321" href="source/drivers/net/ethernet/smsc/smc91x.h#L321">321</a> #include &lt;linux/dma-mapping.h&gt;
<a name="L322" href="source/drivers/net/ethernet/smsc/smc91x.h#L322">322</a> #include &lt;linux/dma/pxa-dma.h&gt;
<a name="L323" href="source/drivers/net/ethernet/smsc/smc91x.h#L323">323</a> 
<a name="L324" href="source/drivers/net/ethernet/smsc/smc91x.h#L324">324</a> #ifdef <a href="ident?i=SMC_insl">SMC_insl</a>
<a name="L325" href="source/drivers/net/ethernet/smsc/smc91x.h#L325">325</a> #undef <a href="ident?i=SMC_insl">SMC_insl</a>
<a name="L326" href="source/drivers/net/ethernet/smsc/smc91x.h#L326">326</a> #define <a href="ident?i=SMC_insl">SMC_insl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>) \
<a name="L327" href="source/drivers/net/ethernet/smsc/smc91x.h#L327">327</a>         <a href="ident?i=smc_pxa_dma_insl">smc_pxa_dma_insl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=lp">lp</a>, <a href="ident?i=r">r</a>, <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=dma">dma</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L328" href="source/drivers/net/ethernet/smsc/smc91x.h#L328">328</a> static inline void
<a name="L329" href="source/drivers/net/ethernet/smsc/smc91x.h#L329">329</a> <a href="ident?i=smc_pxa_dma_inpump">smc_pxa_dma_inpump</a>(struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a>, <a href="ident?i=u_char">u_char</a> *<a href="ident?i=buf">buf</a>, int <a href="ident?i=len">len</a>)
<a name="L330" href="source/drivers/net/ethernet/smsc/smc91x.h#L330">330</a> {
<a name="L331" href="source/drivers/net/ethernet/smsc/smc91x.h#L331">331</a>         <a href="ident?i=dma_addr_t">dma_addr_t</a> <a href="ident?i=dmabuf">dmabuf</a>;
<a name="L332" href="source/drivers/net/ethernet/smsc/smc91x.h#L332">332</a>         struct <a href="ident?i=dma_async_tx_descriptor">dma_async_tx_descriptor</a> *<a href="ident?i=tx">tx</a>;
<a name="L333" href="source/drivers/net/ethernet/smsc/smc91x.h#L333">333</a>         <a href="ident?i=dma_cookie_t">dma_cookie_t</a> cookie;
<a name="L334" href="source/drivers/net/ethernet/smsc/smc91x.h#L334">334</a>         enum <a href="ident?i=dma_status">dma_status</a> <a href="ident?i=status">status</a>;
<a name="L335" href="source/drivers/net/ethernet/smsc/smc91x.h#L335">335</a>         struct <a href="ident?i=dma_tx_state">dma_tx_state</a> <a href="ident?i=state">state</a>;
<a name="L336" href="source/drivers/net/ethernet/smsc/smc91x.h#L336">336</a> 
<a name="L337" href="source/drivers/net/ethernet/smsc/smc91x.h#L337">337</a>         <a href="ident?i=dmabuf">dmabuf</a> = <a href="ident?i=dma_map_single">dma_map_single</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=device">device</a>, <a href="ident?i=buf">buf</a>, <a href="ident?i=len">len</a>, DMA_FROM_DEVICE);
<a name="L338" href="source/drivers/net/ethernet/smsc/smc91x.h#L338">338</a>         <a href="ident?i=tx">tx</a> = <a href="ident?i=dmaengine_prep_slave_single">dmaengine_prep_slave_single</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>, <a href="ident?i=dmabuf">dmabuf</a>, <a href="ident?i=len">len</a>,
<a name="L339" href="source/drivers/net/ethernet/smsc/smc91x.h#L339">339</a>                                          DMA_DEV_TO_MEM, 0);
<a name="L340" href="source/drivers/net/ethernet/smsc/smc91x.h#L340">340</a>         if (<a href="ident?i=tx">tx</a>) {
<a name="L341" href="source/drivers/net/ethernet/smsc/smc91x.h#L341">341</a>                 cookie = <a href="ident?i=dmaengine_submit">dmaengine_submit</a>(<a href="ident?i=tx">tx</a>);
<a name="L342" href="source/drivers/net/ethernet/smsc/smc91x.h#L342">342</a>                 <a href="ident?i=dma_async_issue_pending">dma_async_issue_pending</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>);
<a name="L343" href="source/drivers/net/ethernet/smsc/smc91x.h#L343">343</a>                 do {
<a name="L344" href="source/drivers/net/ethernet/smsc/smc91x.h#L344">344</a>                         <a href="ident?i=status">status</a> = <a href="ident?i=dmaengine_tx_status">dmaengine_tx_status</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>, cookie,
<a name="L345" href="source/drivers/net/ethernet/smsc/smc91x.h#L345">345</a>                                                      &amp;<a href="ident?i=state">state</a>);
<a name="L346" href="source/drivers/net/ethernet/smsc/smc91x.h#L346">346</a>                         <a href="ident?i=cpu_relax">cpu_relax</a>();
<a name="L347" href="source/drivers/net/ethernet/smsc/smc91x.h#L347">347</a>                 } while (<a href="ident?i=status">status</a> != DMA_COMPLETE &amp;&amp; <a href="ident?i=status">status</a> != <a href="ident?i=DMA_ERROR">DMA_ERROR</a> &amp;&amp;
<a name="L348" href="source/drivers/net/ethernet/smsc/smc91x.h#L348">348</a>                          <a href="ident?i=state">state</a>.residue);
<a name="L349" href="source/drivers/net/ethernet/smsc/smc91x.h#L349">349</a>                 <a href="ident?i=dmaengine_terminate_all">dmaengine_terminate_all</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>);
<a name="L350" href="source/drivers/net/ethernet/smsc/smc91x.h#L350">350</a>         }
<a name="L351" href="source/drivers/net/ethernet/smsc/smc91x.h#L351">351</a>         <a href="ident?i=dma_unmap_single">dma_unmap_single</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=device">device</a>, <a href="ident?i=dmabuf">dmabuf</a>, <a href="ident?i=len">len</a>, DMA_FROM_DEVICE);
<a name="L352" href="source/drivers/net/ethernet/smsc/smc91x.h#L352">352</a> }
<a name="L353" href="source/drivers/net/ethernet/smsc/smc91x.h#L353">353</a> 
<a name="L354" href="source/drivers/net/ethernet/smsc/smc91x.h#L354">354</a> static inline void
<a name="L355" href="source/drivers/net/ethernet/smsc/smc91x.h#L355">355</a> <a href="ident?i=smc_pxa_dma_insl">smc_pxa_dma_insl</a>(void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a>, struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a>, int <a href="ident?i=reg">reg</a>, int <a href="ident?i=dma">dma</a>,
<a name="L356" href="source/drivers/net/ethernet/smsc/smc91x.h#L356">356</a>                  <a href="ident?i=u_char">u_char</a> *<a href="ident?i=buf">buf</a>, int <a href="ident?i=len">len</a>)
<a name="L357" href="source/drivers/net/ethernet/smsc/smc91x.h#L357">357</a> {
<a name="L358" href="source/drivers/net/ethernet/smsc/smc91x.h#L358">358</a>         struct <a href="ident?i=dma_slave_config">dma_slave_config</a> <a href="ident?i=config">config</a>;
<a name="L359" href="source/drivers/net/ethernet/smsc/smc91x.h#L359">359</a>         int <a href="ident?i=ret">ret</a>;
<a name="L360" href="source/drivers/net/ethernet/smsc/smc91x.h#L360">360</a> 
<a name="L361" href="source/drivers/net/ethernet/smsc/smc91x.h#L361">361</a>         <b><i>/* fallback if no DMA available */</i></b>
<a name="L362" href="source/drivers/net/ethernet/smsc/smc91x.h#L362">362</a>         if (!<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>) {
<a name="L363" href="source/drivers/net/ethernet/smsc/smc91x.h#L363">363</a>                 <a href="ident?i=readsl">readsl</a>(<a href="ident?i=ioaddr">ioaddr</a> + <a href="ident?i=reg">reg</a>, <a href="ident?i=buf">buf</a>, <a href="ident?i=len">len</a>);
<a name="L364" href="source/drivers/net/ethernet/smsc/smc91x.h#L364">364</a>                 return;
<a name="L365" href="source/drivers/net/ethernet/smsc/smc91x.h#L365">365</a>         }
<a name="L366" href="source/drivers/net/ethernet/smsc/smc91x.h#L366">366</a> 
<a name="L367" href="source/drivers/net/ethernet/smsc/smc91x.h#L367">367</a>         <b><i>/* 64 bit alignment is required for memory to memory DMA */</i></b>
<a name="L368" href="source/drivers/net/ethernet/smsc/smc91x.h#L368">368</a>         if ((long)<a href="ident?i=buf">buf</a> &amp; 4) {
<a name="L369" href="source/drivers/net/ethernet/smsc/smc91x.h#L369">369</a>                 *((<a href="ident?i=u32">u32</a> *)<a href="ident?i=buf">buf</a>) = <a href="ident?i=SMC_inl">SMC_inl</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>);
<a name="L370" href="source/drivers/net/ethernet/smsc/smc91x.h#L370">370</a>                 <a href="ident?i=buf">buf</a> += 4;
<a name="L371" href="source/drivers/net/ethernet/smsc/smc91x.h#L371">371</a>                 <a href="ident?i=len">len</a>--;
<a name="L372" href="source/drivers/net/ethernet/smsc/smc91x.h#L372">372</a>         }
<a name="L373" href="source/drivers/net/ethernet/smsc/smc91x.h#L373">373</a> 
<a name="L374" href="source/drivers/net/ethernet/smsc/smc91x.h#L374">374</a>         <a href="ident?i=memset">memset</a>(&amp;<a href="ident?i=config">config</a>, 0, sizeof(<a href="ident?i=config">config</a>));
<a name="L375" href="source/drivers/net/ethernet/smsc/smc91x.h#L375">375</a>         <a href="ident?i=config">config</a>.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
<a name="L376" href="source/drivers/net/ethernet/smsc/smc91x.h#L376">376</a>         <a href="ident?i=config">config</a>.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
<a name="L377" href="source/drivers/net/ethernet/smsc/smc91x.h#L377">377</a>         <a href="ident?i=config">config</a>.src_addr = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=physaddr">physaddr</a> + <a href="ident?i=reg">reg</a>;
<a name="L378" href="source/drivers/net/ethernet/smsc/smc91x.h#L378">378</a>         <a href="ident?i=config">config</a>.<a href="ident?i=dst_addr">dst_addr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=physaddr">physaddr</a> + <a href="ident?i=reg">reg</a>;
<a name="L379" href="source/drivers/net/ethernet/smsc/smc91x.h#L379">379</a>         <a href="ident?i=config">config</a>.src_maxburst = 32;
<a name="L380" href="source/drivers/net/ethernet/smsc/smc91x.h#L380">380</a>         <a href="ident?i=config">config</a>.dst_maxburst = 32;
<a name="L381" href="source/drivers/net/ethernet/smsc/smc91x.h#L381">381</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=dmaengine_slave_config">dmaengine_slave_config</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>, &amp;<a href="ident?i=config">config</a>);
<a name="L382" href="source/drivers/net/ethernet/smsc/smc91x.h#L382">382</a>         if (<a href="ident?i=ret">ret</a>) {
<a name="L383" href="source/drivers/net/ethernet/smsc/smc91x.h#L383">383</a>                 <a href="ident?i=dev_err">dev_err</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=device">device</a>, <i>"dma channel configuration failed: %d\n"</i>,
<a name="L384" href="source/drivers/net/ethernet/smsc/smc91x.h#L384">384</a>                         <a href="ident?i=ret">ret</a>);
<a name="L385" href="source/drivers/net/ethernet/smsc/smc91x.h#L385">385</a>                 return;
<a name="L386" href="source/drivers/net/ethernet/smsc/smc91x.h#L386">386</a>         }
<a name="L387" href="source/drivers/net/ethernet/smsc/smc91x.h#L387">387</a> 
<a name="L388" href="source/drivers/net/ethernet/smsc/smc91x.h#L388">388</a>         <a href="ident?i=len">len</a> *= 4;
<a name="L389" href="source/drivers/net/ethernet/smsc/smc91x.h#L389">389</a>         <a href="ident?i=smc_pxa_dma_inpump">smc_pxa_dma_inpump</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=buf">buf</a>, <a href="ident?i=len">len</a>);
<a name="L390" href="source/drivers/net/ethernet/smsc/smc91x.h#L390">390</a> }
<a name="L391" href="source/drivers/net/ethernet/smsc/smc91x.h#L391">391</a> #endif
<a name="L392" href="source/drivers/net/ethernet/smsc/smc91x.h#L392">392</a> 
<a name="L393" href="source/drivers/net/ethernet/smsc/smc91x.h#L393">393</a> #ifdef <a href="ident?i=SMC_insw">SMC_insw</a>
<a name="L394" href="source/drivers/net/ethernet/smsc/smc91x.h#L394">394</a> #undef <a href="ident?i=SMC_insw">SMC_insw</a>
<a name="L395" href="source/drivers/net/ethernet/smsc/smc91x.h#L395">395</a> #define <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>) \
<a name="L396" href="source/drivers/net/ethernet/smsc/smc91x.h#L396">396</a>         <a href="ident?i=smc_pxa_dma_insw">smc_pxa_dma_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=lp">lp</a>, <a href="ident?i=r">r</a>, <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=dma">dma</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)
<a name="L397" href="source/drivers/net/ethernet/smsc/smc91x.h#L397">397</a> static inline void
<a name="L398" href="source/drivers/net/ethernet/smsc/smc91x.h#L398">398</a> <a href="ident?i=smc_pxa_dma_insw">smc_pxa_dma_insw</a>(void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a>, struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a>, int <a href="ident?i=reg">reg</a>, int <a href="ident?i=dma">dma</a>,
<a name="L399" href="source/drivers/net/ethernet/smsc/smc91x.h#L399">399</a>                  <a href="ident?i=u_char">u_char</a> *<a href="ident?i=buf">buf</a>, int <a href="ident?i=len">len</a>)
<a name="L400" href="source/drivers/net/ethernet/smsc/smc91x.h#L400">400</a> {
<a name="L401" href="source/drivers/net/ethernet/smsc/smc91x.h#L401">401</a>         struct <a href="ident?i=dma_slave_config">dma_slave_config</a> <a href="ident?i=config">config</a>;
<a name="L402" href="source/drivers/net/ethernet/smsc/smc91x.h#L402">402</a>         int <a href="ident?i=ret">ret</a>;
<a name="L403" href="source/drivers/net/ethernet/smsc/smc91x.h#L403">403</a> 
<a name="L404" href="source/drivers/net/ethernet/smsc/smc91x.h#L404">404</a>         <b><i>/* fallback if no DMA available */</i></b>
<a name="L405" href="source/drivers/net/ethernet/smsc/smc91x.h#L405">405</a>         if (!<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>) {
<a name="L406" href="source/drivers/net/ethernet/smsc/smc91x.h#L406">406</a>                 <a href="ident?i=readsw">readsw</a>(<a href="ident?i=ioaddr">ioaddr</a> + <a href="ident?i=reg">reg</a>, <a href="ident?i=buf">buf</a>, <a href="ident?i=len">len</a>);
<a name="L407" href="source/drivers/net/ethernet/smsc/smc91x.h#L407">407</a>                 return;
<a name="L408" href="source/drivers/net/ethernet/smsc/smc91x.h#L408">408</a>         }
<a name="L409" href="source/drivers/net/ethernet/smsc/smc91x.h#L409">409</a> 
<a name="L410" href="source/drivers/net/ethernet/smsc/smc91x.h#L410">410</a>         <b><i>/* 64 bit alignment is required for memory to memory DMA */</i></b>
<a name="L411" href="source/drivers/net/ethernet/smsc/smc91x.h#L411">411</a>         while ((long)<a href="ident?i=buf">buf</a> &amp; 6) {
<a name="L412" href="source/drivers/net/ethernet/smsc/smc91x.h#L412">412</a>                 *((<a href="ident?i=u16">u16</a> *)<a href="ident?i=buf">buf</a>) = <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>);
<a name="L413" href="source/drivers/net/ethernet/smsc/smc91x.h#L413">413</a>                 <a href="ident?i=buf">buf</a> += 2;
<a name="L414" href="source/drivers/net/ethernet/smsc/smc91x.h#L414">414</a>                 <a href="ident?i=len">len</a>--;
<a name="L415" href="source/drivers/net/ethernet/smsc/smc91x.h#L415">415</a>         }
<a name="L416" href="source/drivers/net/ethernet/smsc/smc91x.h#L416">416</a> 
<a name="L417" href="source/drivers/net/ethernet/smsc/smc91x.h#L417">417</a>         <a href="ident?i=memset">memset</a>(&amp;<a href="ident?i=config">config</a>, 0, sizeof(<a href="ident?i=config">config</a>));
<a name="L418" href="source/drivers/net/ethernet/smsc/smc91x.h#L418">418</a>         <a href="ident?i=config">config</a>.src_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
<a name="L419" href="source/drivers/net/ethernet/smsc/smc91x.h#L419">419</a>         <a href="ident?i=config">config</a>.dst_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
<a name="L420" href="source/drivers/net/ethernet/smsc/smc91x.h#L420">420</a>         <a href="ident?i=config">config</a>.src_addr = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=physaddr">physaddr</a> + <a href="ident?i=reg">reg</a>;
<a name="L421" href="source/drivers/net/ethernet/smsc/smc91x.h#L421">421</a>         <a href="ident?i=config">config</a>.<a href="ident?i=dst_addr">dst_addr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=physaddr">physaddr</a> + <a href="ident?i=reg">reg</a>;
<a name="L422" href="source/drivers/net/ethernet/smsc/smc91x.h#L422">422</a>         <a href="ident?i=config">config</a>.src_maxburst = 32;
<a name="L423" href="source/drivers/net/ethernet/smsc/smc91x.h#L423">423</a>         <a href="ident?i=config">config</a>.dst_maxburst = 32;
<a name="L424" href="source/drivers/net/ethernet/smsc/smc91x.h#L424">424</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=dmaengine_slave_config">dmaengine_slave_config</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>, &amp;<a href="ident?i=config">config</a>);
<a name="L425" href="source/drivers/net/ethernet/smsc/smc91x.h#L425">425</a>         if (<a href="ident?i=ret">ret</a>) {
<a name="L426" href="source/drivers/net/ethernet/smsc/smc91x.h#L426">426</a>                 <a href="ident?i=dev_err">dev_err</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=device">device</a>, <i>"dma channel configuration failed: %d\n"</i>,
<a name="L427" href="source/drivers/net/ethernet/smsc/smc91x.h#L427">427</a>                         <a href="ident?i=ret">ret</a>);
<a name="L428" href="source/drivers/net/ethernet/smsc/smc91x.h#L428">428</a>                 return;
<a name="L429" href="source/drivers/net/ethernet/smsc/smc91x.h#L429">429</a>         }
<a name="L430" href="source/drivers/net/ethernet/smsc/smc91x.h#L430">430</a> 
<a name="L431" href="source/drivers/net/ethernet/smsc/smc91x.h#L431">431</a>         <a href="ident?i=len">len</a> *= 2;
<a name="L432" href="source/drivers/net/ethernet/smsc/smc91x.h#L432">432</a>         <a href="ident?i=smc_pxa_dma_inpump">smc_pxa_dma_inpump</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=buf">buf</a>, <a href="ident?i=len">len</a>);
<a name="L433" href="source/drivers/net/ethernet/smsc/smc91x.h#L433">433</a> }
<a name="L434" href="source/drivers/net/ethernet/smsc/smc91x.h#L434">434</a> #endif
<a name="L435" href="source/drivers/net/ethernet/smsc/smc91x.h#L435">435</a> 
<a name="L436" href="source/drivers/net/ethernet/smsc/smc91x.h#L436">436</a> #endif  <b><i>/* CONFIG_ARCH_PXA */</i></b>
<a name="L437" href="source/drivers/net/ethernet/smsc/smc91x.h#L437">437</a> 
<a name="L438" href="source/drivers/net/ethernet/smsc/smc91x.h#L438">438</a> 
<a name="L439" href="source/drivers/net/ethernet/smsc/smc91x.h#L439">439</a> <b><i>/*</i></b>
<a name="L440" href="source/drivers/net/ethernet/smsc/smc91x.h#L440">440</a> <b><i> * Everything a particular hardware setup needs should have been defined</i></b>
<a name="L441" href="source/drivers/net/ethernet/smsc/smc91x.h#L441">441</a> <b><i> * at this point.  Add stubs for the undefined cases, mainly to avoid</i></b>
<a name="L442" href="source/drivers/net/ethernet/smsc/smc91x.h#L442">442</a> <b><i> * compilation warnings since they'll be optimized away, or to prevent buggy</i></b>
<a name="L443" href="source/drivers/net/ethernet/smsc/smc91x.h#L443">443</a> <b><i> * use of them.</i></b>
<a name="L444" href="source/drivers/net/ethernet/smsc/smc91x.h#L444">444</a> <b><i> */</i></b>
<a name="L445" href="source/drivers/net/ethernet/smsc/smc91x.h#L445">445</a> 
<a name="L446" href="source/drivers/net/ethernet/smsc/smc91x.h#L446">446</a> #if ! <a href="ident?i=SMC_CAN_USE_32BIT">SMC_CAN_USE_32BIT</a>
<a name="L447" href="source/drivers/net/ethernet/smsc/smc91x.h#L447">447</a> #define <a href="ident?i=SMC_inl">SMC_inl</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>)            ({ <a href="ident?i=BUG">BUG</a>(); 0; })
<a name="L448" href="source/drivers/net/ethernet/smsc/smc91x.h#L448">448</a> #define <a href="ident?i=SMC_outl">SMC_outl</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>)        <a href="ident?i=BUG">BUG</a>()
<a name="L449" href="source/drivers/net/ethernet/smsc/smc91x.h#L449">449</a> #define <a href="ident?i=SMC_insl">SMC_insl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)            <a href="ident?i=BUG">BUG</a>()
<a name="L450" href="source/drivers/net/ethernet/smsc/smc91x.h#L450">450</a> #define <a href="ident?i=SMC_outsl">SMC_outsl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)           <a href="ident?i=BUG">BUG</a>()
<a name="L451" href="source/drivers/net/ethernet/smsc/smc91x.h#L451">451</a> #endif
<a name="L452" href="source/drivers/net/ethernet/smsc/smc91x.h#L452">452</a> 
<a name="L453" href="source/drivers/net/ethernet/smsc/smc91x.h#L453">453</a> #if !defined(<a href="ident?i=SMC_insl">SMC_insl</a>) || !defined(<a href="ident?i=SMC_outsl">SMC_outsl</a>)
<a name="L454" href="source/drivers/net/ethernet/smsc/smc91x.h#L454">454</a> #define <a href="ident?i=SMC_insl">SMC_insl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)            <a href="ident?i=BUG">BUG</a>()
<a name="L455" href="source/drivers/net/ethernet/smsc/smc91x.h#L455">455</a> #define <a href="ident?i=SMC_outsl">SMC_outsl</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)           <a href="ident?i=BUG">BUG</a>()
<a name="L456" href="source/drivers/net/ethernet/smsc/smc91x.h#L456">456</a> #endif
<a name="L457" href="source/drivers/net/ethernet/smsc/smc91x.h#L457">457</a> 
<a name="L458" href="source/drivers/net/ethernet/smsc/smc91x.h#L458">458</a> #if ! <a href="ident?i=SMC_CAN_USE_16BIT">SMC_CAN_USE_16BIT</a>
<a name="L459" href="source/drivers/net/ethernet/smsc/smc91x.h#L459">459</a> 
<a name="L460" href="source/drivers/net/ethernet/smsc/smc91x.h#L460">460</a> #define <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>)        <a href="ident?i=SMC_outw_b">SMC_outw_b</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>)
<a name="L461" href="source/drivers/net/ethernet/smsc/smc91x.h#L461">461</a> #define <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>)            <a href="ident?i=SMC_inw_b">SMC_inw_b</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>)
<a name="L462" href="source/drivers/net/ethernet/smsc/smc91x.h#L462">462</a> #define <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)            <a href="ident?i=BUG">BUG</a>()
<a name="L463" href="source/drivers/net/ethernet/smsc/smc91x.h#L463">463</a> #define <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)           <a href="ident?i=BUG">BUG</a>()
<a name="L464" href="source/drivers/net/ethernet/smsc/smc91x.h#L464">464</a> 
<a name="L465" href="source/drivers/net/ethernet/smsc/smc91x.h#L465">465</a> #endif
<a name="L466" href="source/drivers/net/ethernet/smsc/smc91x.h#L466">466</a> 
<a name="L467" href="source/drivers/net/ethernet/smsc/smc91x.h#L467">467</a> #if !defined(<a href="ident?i=SMC_insw">SMC_insw</a>) || !defined(<a href="ident?i=SMC_outsw">SMC_outsw</a>)
<a name="L468" href="source/drivers/net/ethernet/smsc/smc91x.h#L468">468</a> #define <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)            <a href="ident?i=BUG">BUG</a>()
<a name="L469" href="source/drivers/net/ethernet/smsc/smc91x.h#L469">469</a> #define <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)           <a href="ident?i=BUG">BUG</a>()
<a name="L470" href="source/drivers/net/ethernet/smsc/smc91x.h#L470">470</a> #endif
<a name="L471" href="source/drivers/net/ethernet/smsc/smc91x.h#L471">471</a> 
<a name="L472" href="source/drivers/net/ethernet/smsc/smc91x.h#L472">472</a> #if ! <a href="ident?i=SMC_CAN_USE_8BIT">SMC_CAN_USE_8BIT</a>
<a name="L473" href="source/drivers/net/ethernet/smsc/smc91x.h#L473">473</a> #undef <a href="ident?i=SMC_inb">SMC_inb</a>
<a name="L474" href="source/drivers/net/ethernet/smsc/smc91x.h#L474">474</a> #define <a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>)            ({ <a href="ident?i=BUG">BUG</a>(); 0; })
<a name="L475" href="source/drivers/net/ethernet/smsc/smc91x.h#L475">475</a> #undef <a href="ident?i=SMC_outb">SMC_outb</a>
<a name="L476" href="source/drivers/net/ethernet/smsc/smc91x.h#L476">476</a> #define <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=reg">reg</a>)        <a href="ident?i=BUG">BUG</a>()
<a name="L477" href="source/drivers/net/ethernet/smsc/smc91x.h#L477">477</a> #define <a href="ident?i=SMC_insb">SMC_insb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)            <a href="ident?i=BUG">BUG</a>()
<a name="L478" href="source/drivers/net/ethernet/smsc/smc91x.h#L478">478</a> #define <a href="ident?i=SMC_outsb">SMC_outsb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)           <a href="ident?i=BUG">BUG</a>()
<a name="L479" href="source/drivers/net/ethernet/smsc/smc91x.h#L479">479</a> #endif
<a name="L480" href="source/drivers/net/ethernet/smsc/smc91x.h#L480">480</a> 
<a name="L481" href="source/drivers/net/ethernet/smsc/smc91x.h#L481">481</a> #if !defined(<a href="ident?i=SMC_insb">SMC_insb</a>) || !defined(<a href="ident?i=SMC_outsb">SMC_outsb</a>)
<a name="L482" href="source/drivers/net/ethernet/smsc/smc91x.h#L482">482</a> #define <a href="ident?i=SMC_insb">SMC_insb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)            <a href="ident?i=BUG">BUG</a>()
<a name="L483" href="source/drivers/net/ethernet/smsc/smc91x.h#L483">483</a> #define <a href="ident?i=SMC_outsb">SMC_outsb</a>(<a href="ident?i=a">a</a>, <a href="ident?i=r">r</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)           <a href="ident?i=BUG">BUG</a>()
<a name="L484" href="source/drivers/net/ethernet/smsc/smc91x.h#L484">484</a> #endif
<a name="L485" href="source/drivers/net/ethernet/smsc/smc91x.h#L485">485</a> 
<a name="L486" href="source/drivers/net/ethernet/smsc/smc91x.h#L486">486</a> #ifndef <a href="ident?i=SMC_CAN_USE_DATACS">SMC_CAN_USE_DATACS</a>
<a name="L487" href="source/drivers/net/ethernet/smsc/smc91x.h#L487">487</a> #define <a href="ident?i=SMC_CAN_USE_DATACS">SMC_CAN_USE_DATACS</a>      0
<a name="L488" href="source/drivers/net/ethernet/smsc/smc91x.h#L488">488</a> #endif
<a name="L489" href="source/drivers/net/ethernet/smsc/smc91x.h#L489">489</a> 
<a name="L490" href="source/drivers/net/ethernet/smsc/smc91x.h#L490">490</a> #ifndef <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>
<a name="L491" href="source/drivers/net/ethernet/smsc/smc91x.h#L491">491</a> #define <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>    0
<a name="L492" href="source/drivers/net/ethernet/smsc/smc91x.h#L492">492</a> #endif
<a name="L493" href="source/drivers/net/ethernet/smsc/smc91x.h#L493">493</a> 
<a name="L494" href="source/drivers/net/ethernet/smsc/smc91x.h#L494">494</a> #ifndef <a href="ident?i=SMC_IRQ_FLAGS">SMC_IRQ_FLAGS</a>
<a name="L495" href="source/drivers/net/ethernet/smsc/smc91x.h#L495">495</a> #define <a href="ident?i=SMC_IRQ_FLAGS">SMC_IRQ_FLAGS</a>           <a href="ident?i=IRQF_TRIGGER_RISING">IRQF_TRIGGER_RISING</a>
<a name="L496" href="source/drivers/net/ethernet/smsc/smc91x.h#L496">496</a> #endif
<a name="L497" href="source/drivers/net/ethernet/smsc/smc91x.h#L497">497</a> 
<a name="L498" href="source/drivers/net/ethernet/smsc/smc91x.h#L498">498</a> #ifndef <a href="ident?i=SMC_INTERRUPT_PREAMBLE">SMC_INTERRUPT_PREAMBLE</a>
<a name="L499" href="source/drivers/net/ethernet/smsc/smc91x.h#L499">499</a> #define <a href="ident?i=SMC_INTERRUPT_PREAMBLE">SMC_INTERRUPT_PREAMBLE</a>
<a name="L500" href="source/drivers/net/ethernet/smsc/smc91x.h#L500">500</a> #endif
<a name="L501" href="source/drivers/net/ethernet/smsc/smc91x.h#L501">501</a> 
<a name="L502" href="source/drivers/net/ethernet/smsc/smc91x.h#L502">502</a> 
<a name="L503" href="source/drivers/net/ethernet/smsc/smc91x.h#L503">503</a> <b><i>/* Because of bank switching, the LAN91x uses only 16 I/O ports */</i></b>
<a name="L504" href="source/drivers/net/ethernet/smsc/smc91x.h#L504">504</a> #define <a href="ident?i=SMC_IO_EXTENT">SMC_IO_EXTENT</a>   (16 &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>)
<a name="L505" href="source/drivers/net/ethernet/smsc/smc91x.h#L505">505</a> #define <a href="ident?i=SMC_DATA_EXTENT">SMC_DATA_EXTENT</a> (4)
<a name="L506" href="source/drivers/net/ethernet/smsc/smc91x.h#L506">506</a> 
<a name="L507" href="source/drivers/net/ethernet/smsc/smc91x.h#L507">507</a> <b><i>/*</i></b>
<a name="L508" href="source/drivers/net/ethernet/smsc/smc91x.h#L508">508</a> <b><i> . Bank Select Register:</i></b>
<a name="L509" href="source/drivers/net/ethernet/smsc/smc91x.h#L509">509</a> <b><i> .</i></b>
<a name="L510" href="source/drivers/net/ethernet/smsc/smc91x.h#L510">510</a> <b><i> .              yyyy yyyy 0000 00xx</i></b>
<a name="L511" href="source/drivers/net/ethernet/smsc/smc91x.h#L511">511</a> <b><i> .              xx              = bank number</i></b>
<a name="L512" href="source/drivers/net/ethernet/smsc/smc91x.h#L512">512</a> <b><i> .              yyyy yyyy       = 0x33, for identification purposes.</i></b>
<a name="L513" href="source/drivers/net/ethernet/smsc/smc91x.h#L513">513</a> <b><i>*/</i></b>
<a name="L514" href="source/drivers/net/ethernet/smsc/smc91x.h#L514">514</a> #define <a href="ident?i=BANK_SELECT">BANK_SELECT</a>             (14 &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>)
<a name="L515" href="source/drivers/net/ethernet/smsc/smc91x.h#L515">515</a> 
<a name="L516" href="source/drivers/net/ethernet/smsc/smc91x.h#L516">516</a> 
<a name="L517" href="source/drivers/net/ethernet/smsc/smc91x.h#L517">517</a> <b><i>// Transmit Control Register</i></b>
<a name="L518" href="source/drivers/net/ethernet/smsc/smc91x.h#L518">518</a> <b><i></i></b><b><i>/* BANK 0  */</i></b>
<a name="L519" href="source/drivers/net/ethernet/smsc/smc91x.h#L519">519</a> #define <a href="ident?i=TCR_REG">TCR_REG</a>(<a href="ident?i=lp">lp</a>)     <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0000, 0)
<a name="L520" href="source/drivers/net/ethernet/smsc/smc91x.h#L520">520</a> #define <a href="ident?i=TCR_ENABLE">TCR_ENABLE</a>      0x0001  <b><i>// When 1 we can transmit</i></b>
<a name="L521" href="source/drivers/net/ethernet/smsc/smc91x.h#L521">521</a> <b><i></i></b>#define <a href="ident?i=TCR_LOOP">TCR_LOOP</a>        0x0002  <b><i>// Controls output pin LBK</i></b>
<a name="L522" href="source/drivers/net/ethernet/smsc/smc91x.h#L522">522</a> <b><i></i></b>#define <a href="ident?i=TCR_FORCOL">TCR_FORCOL</a>      0x0004  <b><i>// When 1 will force a collision</i></b>
<a name="L523" href="source/drivers/net/ethernet/smsc/smc91x.h#L523">523</a> <b><i></i></b>#define <a href="ident?i=TCR_PAD_EN">TCR_PAD_EN</a>      0x0080  <b><i>// When 1 will pad tx frames &lt; 64 bytes w/0</i></b>
<a name="L524" href="source/drivers/net/ethernet/smsc/smc91x.h#L524">524</a> <b><i></i></b>#define <a href="ident?i=TCR_NOCRC">TCR_NOCRC</a>       0x0100  <b><i>// When 1 will not append CRC to tx frames</i></b>
<a name="L525" href="source/drivers/net/ethernet/smsc/smc91x.h#L525">525</a> <b><i></i></b>#define <a href="ident?i=TCR_MON_CSN">TCR_MON_CSN</a>     0x0400  <b><i>// When 1 tx monitors carrier</i></b>
<a name="L526" href="source/drivers/net/ethernet/smsc/smc91x.h#L526">526</a> <b><i></i></b>#define <a href="ident?i=TCR_FDUPLX">TCR_FDUPLX</a>      0x0800  <b><i>// When 1 enables full duplex operation</i></b>
<a name="L527" href="source/drivers/net/ethernet/smsc/smc91x.h#L527">527</a> <b><i></i></b>#define <a href="ident?i=TCR_STP_SQET">TCR_STP_SQET</a>    0x1000  <b><i>// When 1 stops tx if Signal Quality Error</i></b>
<a name="L528" href="source/drivers/net/ethernet/smsc/smc91x.h#L528">528</a> <b><i></i></b>#define <a href="ident?i=TCR_EPH_LOOP">TCR_EPH_LOOP</a>    0x2000  <b><i>// When 1 enables EPH block loopback</i></b>
<a name="L529" href="source/drivers/net/ethernet/smsc/smc91x.h#L529">529</a> <b><i></i></b>#define <a href="ident?i=TCR_SWFDUP">TCR_SWFDUP</a>      0x8000  <b><i>// When 1 enables Switched Full Duplex mode</i></b>
<a name="L530" href="source/drivers/net/ethernet/smsc/smc91x.h#L530">530</a> <b><i></i></b>
<a name="L531" href="source/drivers/net/ethernet/smsc/smc91x.h#L531">531</a> #define <a href="ident?i=TCR_CLEAR">TCR_CLEAR</a>       0       <b><i>/* do NOTHING */</i></b>
<a name="L532" href="source/drivers/net/ethernet/smsc/smc91x.h#L532">532</a> <b><i>/* the default settings for the TCR register : */</i></b>
<a name="L533" href="source/drivers/net/ethernet/smsc/smc91x.h#L533">533</a> #define <a href="ident?i=TCR_DEFAULT">TCR_DEFAULT</a>     (<a href="ident?i=TCR_ENABLE">TCR_ENABLE</a> | <a href="ident?i=TCR_PAD_EN">TCR_PAD_EN</a>)
<a name="L534" href="source/drivers/net/ethernet/smsc/smc91x.h#L534">534</a> 
<a name="L535" href="source/drivers/net/ethernet/smsc/smc91x.h#L535">535</a> 
<a name="L536" href="source/drivers/net/ethernet/smsc/smc91x.h#L536">536</a> <b><i>// EPH Status Register</i></b>
<a name="L537" href="source/drivers/net/ethernet/smsc/smc91x.h#L537">537</a> <b><i></i></b><b><i>/* BANK 0  */</i></b>
<a name="L538" href="source/drivers/net/ethernet/smsc/smc91x.h#L538">538</a> #define <a href="ident?i=EPH_STATUS_REG">EPH_STATUS_REG</a>(<a href="ident?i=lp">lp</a>)      <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0002, 0)
<a name="L539" href="source/drivers/net/ethernet/smsc/smc91x.h#L539">539</a> #define <a href="ident?i=ES_TX_SUC">ES_TX_SUC</a>       0x0001  <b><i>// Last TX was successful</i></b>
<a name="L540" href="source/drivers/net/ethernet/smsc/smc91x.h#L540">540</a> <b><i></i></b>#define <a href="ident?i=ES_SNGL_COL">ES_SNGL_COL</a>     0x0002  <b><i>// Single collision detected for last tx</i></b>
<a name="L541" href="source/drivers/net/ethernet/smsc/smc91x.h#L541">541</a> <b><i></i></b>#define <a href="ident?i=ES_MUL_COL">ES_MUL_COL</a>      0x0004  <b><i>// Multiple collisions detected for last tx</i></b>
<a name="L542" href="source/drivers/net/ethernet/smsc/smc91x.h#L542">542</a> <b><i></i></b>#define <a href="ident?i=ES_LTX_MULT">ES_LTX_MULT</a>     0x0008  <b><i>// Last tx was a multicast</i></b>
<a name="L543" href="source/drivers/net/ethernet/smsc/smc91x.h#L543">543</a> <b><i></i></b>#define <a href="ident?i=ES_16COL">ES_16COL</a>        0x0010  <b><i>// 16 Collisions Reached</i></b>
<a name="L544" href="source/drivers/net/ethernet/smsc/smc91x.h#L544">544</a> <b><i></i></b>#define <a href="ident?i=ES_SQET">ES_SQET</a>         0x0020  <b><i>// Signal Quality Error Test</i></b>
<a name="L545" href="source/drivers/net/ethernet/smsc/smc91x.h#L545">545</a> <b><i></i></b>#define <a href="ident?i=ES_LTXBRD">ES_LTXBRD</a>       0x0040  <b><i>// Last tx was a broadcast</i></b>
<a name="L546" href="source/drivers/net/ethernet/smsc/smc91x.h#L546">546</a> <b><i></i></b>#define <a href="ident?i=ES_TXDEFR">ES_TXDEFR</a>       0x0080  <b><i>// Transmit Deferred</i></b>
<a name="L547" href="source/drivers/net/ethernet/smsc/smc91x.h#L547">547</a> <b><i></i></b>#define <a href="ident?i=ES_LATCOL">ES_LATCOL</a>       0x0200  <b><i>// Late collision detected on last tx</i></b>
<a name="L548" href="source/drivers/net/ethernet/smsc/smc91x.h#L548">548</a> <b><i></i></b>#define <a href="ident?i=ES_LOSTCARR">ES_LOSTCARR</a>     0x0400  <b><i>// Lost Carrier Sense</i></b>
<a name="L549" href="source/drivers/net/ethernet/smsc/smc91x.h#L549">549</a> <b><i></i></b>#define <a href="ident?i=ES_EXC_DEF">ES_EXC_DEF</a>      0x0800  <b><i>// Excessive Deferral</i></b>
<a name="L550" href="source/drivers/net/ethernet/smsc/smc91x.h#L550">550</a> <b><i></i></b>#define <a href="ident?i=ES_CTR_ROL">ES_CTR_ROL</a>      0x1000  <b><i>// Counter Roll Over indication</i></b>
<a name="L551" href="source/drivers/net/ethernet/smsc/smc91x.h#L551">551</a> <b><i></i></b>#define <a href="ident?i=ES_LINK_OK">ES_LINK_OK</a>      0x4000  <b><i>// Driven by inverted value of nLNK pin</i></b>
<a name="L552" href="source/drivers/net/ethernet/smsc/smc91x.h#L552">552</a> <b><i></i></b>#define <a href="ident?i=ES_TXUNRN">ES_TXUNRN</a>       0x8000  <b><i>// Tx Underrun</i></b>
<a name="L553" href="source/drivers/net/ethernet/smsc/smc91x.h#L553">553</a> <b><i></i></b>
<a name="L554" href="source/drivers/net/ethernet/smsc/smc91x.h#L554">554</a> 
<a name="L555" href="source/drivers/net/ethernet/smsc/smc91x.h#L555">555</a> <b><i>// Receive Control Register</i></b>
<a name="L556" href="source/drivers/net/ethernet/smsc/smc91x.h#L556">556</a> <b><i></i></b><b><i>/* BANK 0  */</i></b>
<a name="L557" href="source/drivers/net/ethernet/smsc/smc91x.h#L557">557</a> #define <a href="ident?i=RCR_REG">RCR_REG</a>(<a href="ident?i=lp">lp</a>)             <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0004, 0)
<a name="L558" href="source/drivers/net/ethernet/smsc/smc91x.h#L558">558</a> #define <a href="ident?i=RCR_RX_ABORT">RCR_RX_ABORT</a>    0x0001  <b><i>// Set if a rx frame was aborted</i></b>
<a name="L559" href="source/drivers/net/ethernet/smsc/smc91x.h#L559">559</a> <b><i></i></b>#define <a href="ident?i=RCR_PRMS">RCR_PRMS</a>        0x0002  <b><i>// Enable promiscuous mode</i></b>
<a name="L560" href="source/drivers/net/ethernet/smsc/smc91x.h#L560">560</a> <b><i></i></b>#define <a href="ident?i=RCR_ALMUL">RCR_ALMUL</a>       0x0004  <b><i>// When set accepts all multicast frames</i></b>
<a name="L561" href="source/drivers/net/ethernet/smsc/smc91x.h#L561">561</a> <b><i></i></b>#define <a href="ident?i=RCR_RXEN">RCR_RXEN</a>        0x0100  <b><i>// IFF this is set, we can receive packets</i></b>
<a name="L562" href="source/drivers/net/ethernet/smsc/smc91x.h#L562">562</a> <b><i></i></b>#define <a href="ident?i=RCR_STRIP_CRC">RCR_STRIP_CRC</a>   0x0200  <b><i>// When set strips CRC from rx packets</i></b>
<a name="L563" href="source/drivers/net/ethernet/smsc/smc91x.h#L563">563</a> <b><i></i></b>#define <a href="ident?i=RCR_ABORT_ENB">RCR_ABORT_ENB</a>   0x0200  <b><i>// When set will abort rx on collision</i></b>
<a name="L564" href="source/drivers/net/ethernet/smsc/smc91x.h#L564">564</a> <b><i></i></b>#define <a href="ident?i=RCR_FILT_CAR">RCR_FILT_CAR</a>    0x0400  <b><i>// When set filters leading 12 bit s of carrier</i></b>
<a name="L565" href="source/drivers/net/ethernet/smsc/smc91x.h#L565">565</a> <b><i></i></b>#define <a href="ident?i=RCR_SOFTRST">RCR_SOFTRST</a>     0x8000  <b><i>// resets the chip</i></b>
<a name="L566" href="source/drivers/net/ethernet/smsc/smc91x.h#L566">566</a> <b><i></i></b>
<a name="L567" href="source/drivers/net/ethernet/smsc/smc91x.h#L567">567</a> <b><i>/* the normal settings for the RCR register : */</i></b>
<a name="L568" href="source/drivers/net/ethernet/smsc/smc91x.h#L568">568</a> #define <a href="ident?i=RCR_DEFAULT">RCR_DEFAULT</a>     (<a href="ident?i=RCR_STRIP_CRC">RCR_STRIP_CRC</a> | <a href="ident?i=RCR_RXEN">RCR_RXEN</a>)
<a name="L569" href="source/drivers/net/ethernet/smsc/smc91x.h#L569">569</a> #define <a href="ident?i=RCR_CLEAR">RCR_CLEAR</a>       0x0     <b><i>// set it to a base state</i></b>
<a name="L570" href="source/drivers/net/ethernet/smsc/smc91x.h#L570">570</a> <b><i></i></b>
<a name="L571" href="source/drivers/net/ethernet/smsc/smc91x.h#L571">571</a> 
<a name="L572" href="source/drivers/net/ethernet/smsc/smc91x.h#L572">572</a> <b><i>// Counter Register</i></b>
<a name="L573" href="source/drivers/net/ethernet/smsc/smc91x.h#L573">573</a> <b><i></i></b><b><i>/* BANK 0  */</i></b>
<a name="L574" href="source/drivers/net/ethernet/smsc/smc91x.h#L574">574</a> #define <a href="ident?i=COUNTER_REG">COUNTER_REG</a>(<a href="ident?i=lp">lp</a>) <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0006, 0)
<a name="L575" href="source/drivers/net/ethernet/smsc/smc91x.h#L575">575</a> 
<a name="L576" href="source/drivers/net/ethernet/smsc/smc91x.h#L576">576</a> 
<a name="L577" href="source/drivers/net/ethernet/smsc/smc91x.h#L577">577</a> <b><i>// Memory Information Register</i></b>
<a name="L578" href="source/drivers/net/ethernet/smsc/smc91x.h#L578">578</a> <b><i></i></b><b><i>/* BANK 0  */</i></b>
<a name="L579" href="source/drivers/net/ethernet/smsc/smc91x.h#L579">579</a> #define <a href="ident?i=MIR_REG">MIR_REG</a>(<a href="ident?i=lp">lp</a>)             <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0008, 0)
<a name="L580" href="source/drivers/net/ethernet/smsc/smc91x.h#L580">580</a> 
<a name="L581" href="source/drivers/net/ethernet/smsc/smc91x.h#L581">581</a> 
<a name="L582" href="source/drivers/net/ethernet/smsc/smc91x.h#L582">582</a> <b><i>// Receive/Phy Control Register</i></b>
<a name="L583" href="source/drivers/net/ethernet/smsc/smc91x.h#L583">583</a> <b><i></i></b><b><i>/* BANK 0  */</i></b>
<a name="L584" href="source/drivers/net/ethernet/smsc/smc91x.h#L584">584</a> #define <a href="ident?i=RPC_REG">RPC_REG</a>(<a href="ident?i=lp">lp</a>)             <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x000A, 0)
<a name="L585" href="source/drivers/net/ethernet/smsc/smc91x.h#L585">585</a> #define <a href="ident?i=RPC_SPEED">RPC_SPEED</a>       0x2000  <b><i>// When 1 PHY is in 100Mbps mode.</i></b>
<a name="L586" href="source/drivers/net/ethernet/smsc/smc91x.h#L586">586</a> <b><i></i></b>#define <a href="ident?i=RPC_DPLX">RPC_DPLX</a>        0x1000  <b><i>// When 1 PHY is in Full-Duplex Mode</i></b>
<a name="L587" href="source/drivers/net/ethernet/smsc/smc91x.h#L587">587</a> <b><i></i></b>#define <a href="ident?i=RPC_ANEG">RPC_ANEG</a>        0x0800  <b><i>// When 1 PHY is in Auto-Negotiate Mode</i></b>
<a name="L588" href="source/drivers/net/ethernet/smsc/smc91x.h#L588">588</a> <b><i></i></b>#define <a href="ident?i=RPC_LSXA_SHFT">RPC_LSXA_SHFT</a>   5       <b><i>// Bits to shift LS2A,LS1A,LS0A to lsb</i></b>
<a name="L589" href="source/drivers/net/ethernet/smsc/smc91x.h#L589">589</a> <b><i></i></b>#define <a href="ident?i=RPC_LSXB_SHFT">RPC_LSXB_SHFT</a>   2       <b><i>// Bits to get LS2B,LS1B,LS0B to lsb</i></b>
<a name="L590" href="source/drivers/net/ethernet/smsc/smc91x.h#L590">590</a> <b><i></i></b>
<a name="L591" href="source/drivers/net/ethernet/smsc/smc91x.h#L591">591</a> #ifndef <a href="ident?i=RPC_LSA_DEFAULT">RPC_LSA_DEFAULT</a>
<a name="L592" href="source/drivers/net/ethernet/smsc/smc91x.h#L592">592</a> #define <a href="ident?i=RPC_LSA_DEFAULT">RPC_LSA_DEFAULT</a> <a href="ident?i=RPC_LED_100">RPC_LED_100</a>
<a name="L593" href="source/drivers/net/ethernet/smsc/smc91x.h#L593">593</a> #endif
<a name="L594" href="source/drivers/net/ethernet/smsc/smc91x.h#L594">594</a> #ifndef <a href="ident?i=RPC_LSB_DEFAULT">RPC_LSB_DEFAULT</a>
<a name="L595" href="source/drivers/net/ethernet/smsc/smc91x.h#L595">595</a> #define <a href="ident?i=RPC_LSB_DEFAULT">RPC_LSB_DEFAULT</a> <a href="ident?i=RPC_LED_FD">RPC_LED_FD</a>
<a name="L596" href="source/drivers/net/ethernet/smsc/smc91x.h#L596">596</a> #endif
<a name="L597" href="source/drivers/net/ethernet/smsc/smc91x.h#L597">597</a> 
<a name="L598" href="source/drivers/net/ethernet/smsc/smc91x.h#L598">598</a> #define <a href="ident?i=RPC_DEFAULT">RPC_DEFAULT</a> (<a href="ident?i=RPC_ANEG">RPC_ANEG</a> | <a href="ident?i=RPC_SPEED">RPC_SPEED</a> | <a href="ident?i=RPC_DPLX">RPC_DPLX</a>)
<a name="L599" href="source/drivers/net/ethernet/smsc/smc91x.h#L599">599</a> 
<a name="L600" href="source/drivers/net/ethernet/smsc/smc91x.h#L600">600</a> 
<a name="L601" href="source/drivers/net/ethernet/smsc/smc91x.h#L601">601</a> <b><i>/* Bank 0 0x0C is reserved */</i></b>
<a name="L602" href="source/drivers/net/ethernet/smsc/smc91x.h#L602">602</a> 
<a name="L603" href="source/drivers/net/ethernet/smsc/smc91x.h#L603">603</a> <b><i>// Bank Select Register</i></b>
<a name="L604" href="source/drivers/net/ethernet/smsc/smc91x.h#L604">604</a> <b><i></i></b><b><i>/* All Banks */</i></b>
<a name="L605" href="source/drivers/net/ethernet/smsc/smc91x.h#L605">605</a> #define <a href="ident?i=BSR_REG">BSR_REG</a>         0x000E
<a name="L606" href="source/drivers/net/ethernet/smsc/smc91x.h#L606">606</a> 
<a name="L607" href="source/drivers/net/ethernet/smsc/smc91x.h#L607">607</a> 
<a name="L608" href="source/drivers/net/ethernet/smsc/smc91x.h#L608">608</a> <b><i>// Configuration Reg</i></b>
<a name="L609" href="source/drivers/net/ethernet/smsc/smc91x.h#L609">609</a> <b><i></i></b><b><i>/* BANK 1 */</i></b>
<a name="L610" href="source/drivers/net/ethernet/smsc/smc91x.h#L610">610</a> #define <a href="ident?i=CONFIG_REG">CONFIG_REG</a>(<a href="ident?i=lp">lp</a>)  <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0000,     1)
<a name="L611" href="source/drivers/net/ethernet/smsc/smc91x.h#L611">611</a> #define <a href="ident?i=CONFIG_EXT_PHY">CONFIG_EXT_PHY</a>  0x0200  <b><i>// 1=external MII, 0=internal Phy</i></b>
<a name="L612" href="source/drivers/net/ethernet/smsc/smc91x.h#L612">612</a> <b><i></i></b>#define <a href="ident?i=CONFIG_GPCNTRL">CONFIG_GPCNTRL</a>  0x0400  <b><i>// Inverse value drives pin nCNTRL</i></b>
<a name="L613" href="source/drivers/net/ethernet/smsc/smc91x.h#L613">613</a> <b><i></i></b>#define <a href="ident?i=CONFIG_NO_WAIT">CONFIG_NO_WAIT</a>  0x1000  <b><i>// When 1 no extra wait states on ISA bus</i></b>
<a name="L614" href="source/drivers/net/ethernet/smsc/smc91x.h#L614">614</a> <b><i></i></b>#define <a href="ident?i=CONFIG_EPH_POWER_EN">CONFIG_EPH_POWER_EN</a> 0x8000 <b><i>// When 0 EPH is placed into low power mode.</i></b>
<a name="L615" href="source/drivers/net/ethernet/smsc/smc91x.h#L615">615</a> <b><i></i></b>
<a name="L616" href="source/drivers/net/ethernet/smsc/smc91x.h#L616">616</a> <b><i>// Default is powered-up, Internal Phy, Wait States, and pin nCNTRL=low</i></b>
<a name="L617" href="source/drivers/net/ethernet/smsc/smc91x.h#L617">617</a> <b><i></i></b>#define <a href="ident?i=CONFIG_DEFAULT">CONFIG_DEFAULT</a>  (<a href="ident?i=CONFIG_EPH_POWER_EN">CONFIG_EPH_POWER_EN</a>)
<a name="L618" href="source/drivers/net/ethernet/smsc/smc91x.h#L618">618</a> 
<a name="L619" href="source/drivers/net/ethernet/smsc/smc91x.h#L619">619</a> 
<a name="L620" href="source/drivers/net/ethernet/smsc/smc91x.h#L620">620</a> <b><i>// Base Address Register</i></b>
<a name="L621" href="source/drivers/net/ethernet/smsc/smc91x.h#L621">621</a> <b><i></i></b><b><i>/* BANK 1 */</i></b>
<a name="L622" href="source/drivers/net/ethernet/smsc/smc91x.h#L622">622</a> #define <a href="ident?i=BASE_REG">BASE_REG</a>(<a href="ident?i=lp">lp</a>)    <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0002, 1)
<a name="L623" href="source/drivers/net/ethernet/smsc/smc91x.h#L623">623</a> 
<a name="L624" href="source/drivers/net/ethernet/smsc/smc91x.h#L624">624</a> 
<a name="L625" href="source/drivers/net/ethernet/smsc/smc91x.h#L625">625</a> <b><i>// Individual Address Registers</i></b>
<a name="L626" href="source/drivers/net/ethernet/smsc/smc91x.h#L626">626</a> <b><i></i></b><b><i>/* BANK 1 */</i></b>
<a name="L627" href="source/drivers/net/ethernet/smsc/smc91x.h#L627">627</a> #define <a href="ident?i=ADDR0_REG">ADDR0_REG</a>(<a href="ident?i=lp">lp</a>)   <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0004, 1)
<a name="L628" href="source/drivers/net/ethernet/smsc/smc91x.h#L628">628</a> #define <a href="ident?i=ADDR1_REG">ADDR1_REG</a>(<a href="ident?i=lp">lp</a>)   <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0006, 1)
<a name="L629" href="source/drivers/net/ethernet/smsc/smc91x.h#L629">629</a> #define <a href="ident?i=ADDR2_REG">ADDR2_REG</a>(<a href="ident?i=lp">lp</a>)   <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0008, 1)
<a name="L630" href="source/drivers/net/ethernet/smsc/smc91x.h#L630">630</a> 
<a name="L631" href="source/drivers/net/ethernet/smsc/smc91x.h#L631">631</a> 
<a name="L632" href="source/drivers/net/ethernet/smsc/smc91x.h#L632">632</a> <b><i>// General Purpose Register</i></b>
<a name="L633" href="source/drivers/net/ethernet/smsc/smc91x.h#L633">633</a> <b><i></i></b><b><i>/* BANK 1 */</i></b>
<a name="L634" href="source/drivers/net/ethernet/smsc/smc91x.h#L634">634</a> #define <a href="ident?i=GP_REG">GP_REG</a>(<a href="ident?i=lp">lp</a>)              <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x000A, 1)
<a name="L635" href="source/drivers/net/ethernet/smsc/smc91x.h#L635">635</a> 
<a name="L636" href="source/drivers/net/ethernet/smsc/smc91x.h#L636">636</a> 
<a name="L637" href="source/drivers/net/ethernet/smsc/smc91x.h#L637">637</a> <b><i>// Control Register</i></b>
<a name="L638" href="source/drivers/net/ethernet/smsc/smc91x.h#L638">638</a> <b><i></i></b><b><i>/* BANK 1 */</i></b>
<a name="L639" href="source/drivers/net/ethernet/smsc/smc91x.h#L639">639</a> #define <a href="ident?i=CTL_REG">CTL_REG</a>(<a href="ident?i=lp">lp</a>)             <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x000C, 1)
<a name="L640" href="source/drivers/net/ethernet/smsc/smc91x.h#L640">640</a> #define <a href="ident?i=CTL_RCV_BAD">CTL_RCV_BAD</a>     0x4000 <b><i>// When 1 bad CRC packets are received</i></b>
<a name="L641" href="source/drivers/net/ethernet/smsc/smc91x.h#L641">641</a> <b><i></i></b>#define <a href="ident?i=CTL_AUTO_RELEASE">CTL_AUTO_RELEASE</a> 0x0800 <b><i>// When 1 tx pages are released automatically</i></b>
<a name="L642" href="source/drivers/net/ethernet/smsc/smc91x.h#L642">642</a> <b><i></i></b>#define <a href="ident?i=CTL_LE_ENABLE">CTL_LE_ENABLE</a>   0x0080 <b><i>// When 1 enables Link Error interrupt</i></b>
<a name="L643" href="source/drivers/net/ethernet/smsc/smc91x.h#L643">643</a> <b><i></i></b>#define <a href="ident?i=CTL_CR_ENABLE">CTL_CR_ENABLE</a>   0x0040 <b><i>// When 1 enables Counter Rollover interrupt</i></b>
<a name="L644" href="source/drivers/net/ethernet/smsc/smc91x.h#L644">644</a> <b><i></i></b>#define <a href="ident?i=CTL_TE_ENABLE">CTL_TE_ENABLE</a>   0x0020 <b><i>// When 1 enables Transmit Error interrupt</i></b>
<a name="L645" href="source/drivers/net/ethernet/smsc/smc91x.h#L645">645</a> <b><i></i></b>#define <a href="ident?i=CTL_EEPROM_SELECT">CTL_EEPROM_SELECT</a> 0x0004 <b><i>// Controls EEPROM reload &amp; store</i></b>
<a name="L646" href="source/drivers/net/ethernet/smsc/smc91x.h#L646">646</a> <b><i></i></b>#define <a href="ident?i=CTL_RELOAD">CTL_RELOAD</a>      0x0002 <b><i>// When set reads EEPROM into registers</i></b>
<a name="L647" href="source/drivers/net/ethernet/smsc/smc91x.h#L647">647</a> <b><i></i></b>#define <a href="ident?i=CTL_STORE">CTL_STORE</a>       0x0001 <b><i>// When set stores registers into EEPROM</i></b>
<a name="L648" href="source/drivers/net/ethernet/smsc/smc91x.h#L648">648</a> <b><i></i></b>
<a name="L649" href="source/drivers/net/ethernet/smsc/smc91x.h#L649">649</a> 
<a name="L650" href="source/drivers/net/ethernet/smsc/smc91x.h#L650">650</a> <b><i>// MMU Command Register</i></b>
<a name="L651" href="source/drivers/net/ethernet/smsc/smc91x.h#L651">651</a> <b><i></i></b><b><i>/* BANK 2 */</i></b>
<a name="L652" href="source/drivers/net/ethernet/smsc/smc91x.h#L652">652</a> #define <a href="ident?i=MMU_CMD_REG">MMU_CMD_REG</a>(<a href="ident?i=lp">lp</a>) <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0000, 2)
<a name="L653" href="source/drivers/net/ethernet/smsc/smc91x.h#L653">653</a> #define <a href="ident?i=MC_BUSY">MC_BUSY</a>         1       <b><i>// When 1 the last release has not completed</i></b>
<a name="L654" href="source/drivers/net/ethernet/smsc/smc91x.h#L654">654</a> <b><i></i></b>#define <a href="ident?i=MC_NOP">MC_NOP</a>          (0&lt;&lt;5)  <b><i>// No Op</i></b>
<a name="L655" href="source/drivers/net/ethernet/smsc/smc91x.h#L655">655</a> <b><i></i></b>#define <a href="ident?i=MC_ALLOC">MC_ALLOC</a>        (1&lt;&lt;5)  <b><i>// OR with number of 256 byte packets</i></b>
<a name="L656" href="source/drivers/net/ethernet/smsc/smc91x.h#L656">656</a> <b><i></i></b>#define <a href="ident?i=MC_RESET">MC_RESET</a>        (2&lt;&lt;5)  <b><i>// Reset MMU to initial state</i></b>
<a name="L657" href="source/drivers/net/ethernet/smsc/smc91x.h#L657">657</a> <b><i></i></b>#define <a href="ident?i=MC_REMOVE">MC_REMOVE</a>       (3&lt;&lt;5)  <b><i>// Remove the current rx packet</i></b>
<a name="L658" href="source/drivers/net/ethernet/smsc/smc91x.h#L658">658</a> <b><i></i></b>#define <a href="ident?i=MC_RELEASE">MC_RELEASE</a>      (4&lt;&lt;5)  <b><i>// Remove and release the current rx packet</i></b>
<a name="L659" href="source/drivers/net/ethernet/smsc/smc91x.h#L659">659</a> <b><i></i></b>#define <a href="ident?i=MC_FREEPKT">MC_FREEPKT</a>      (5&lt;&lt;5)  <b><i>// Release packet in PNR register</i></b>
<a name="L660" href="source/drivers/net/ethernet/smsc/smc91x.h#L660">660</a> <b><i></i></b>#define <a href="ident?i=MC_ENQUEUE">MC_ENQUEUE</a>      (6&lt;&lt;5)  <b><i>// Enqueue the packet for transmit</i></b>
<a name="L661" href="source/drivers/net/ethernet/smsc/smc91x.h#L661">661</a> <b><i></i></b>#define <a href="ident?i=MC_RSTTXFIFO">MC_RSTTXFIFO</a>    (7&lt;&lt;5)  <b><i>// Reset the TX FIFOs</i></b>
<a name="L662" href="source/drivers/net/ethernet/smsc/smc91x.h#L662">662</a> <b><i></i></b>
<a name="L663" href="source/drivers/net/ethernet/smsc/smc91x.h#L663">663</a> 
<a name="L664" href="source/drivers/net/ethernet/smsc/smc91x.h#L664">664</a> <b><i>// Packet Number Register</i></b>
<a name="L665" href="source/drivers/net/ethernet/smsc/smc91x.h#L665">665</a> <b><i></i></b><b><i>/* BANK 2 */</i></b>
<a name="L666" href="source/drivers/net/ethernet/smsc/smc91x.h#L666">666</a> #define <a href="ident?i=PN_REG">PN_REG</a>(<a href="ident?i=lp">lp</a>)              <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0002, 2)
<a name="L667" href="source/drivers/net/ethernet/smsc/smc91x.h#L667">667</a> 
<a name="L668" href="source/drivers/net/ethernet/smsc/smc91x.h#L668">668</a> 
<a name="L669" href="source/drivers/net/ethernet/smsc/smc91x.h#L669">669</a> <b><i>// Allocation Result Register</i></b>
<a name="L670" href="source/drivers/net/ethernet/smsc/smc91x.h#L670">670</a> <b><i></i></b><b><i>/* BANK 2 */</i></b>
<a name="L671" href="source/drivers/net/ethernet/smsc/smc91x.h#L671">671</a> #define <a href="ident?i=AR_REG">AR_REG</a>(<a href="ident?i=lp">lp</a>)              <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0003, 2)
<a name="L672" href="source/drivers/net/ethernet/smsc/smc91x.h#L672">672</a> #define <a href="ident?i=AR_FAILED">AR_FAILED</a>       0x80    <b><i>// Alocation Failed</i></b>
<a name="L673" href="source/drivers/net/ethernet/smsc/smc91x.h#L673">673</a> <b><i></i></b>
<a name="L674" href="source/drivers/net/ethernet/smsc/smc91x.h#L674">674</a> 
<a name="L675" href="source/drivers/net/ethernet/smsc/smc91x.h#L675">675</a> <b><i>// TX FIFO Ports Register</i></b>
<a name="L676" href="source/drivers/net/ethernet/smsc/smc91x.h#L676">676</a> <b><i></i></b><b><i>/* BANK 2 */</i></b>
<a name="L677" href="source/drivers/net/ethernet/smsc/smc91x.h#L677">677</a> #define <a href="ident?i=TXFIFO_REG">TXFIFO_REG</a>(<a href="ident?i=lp">lp</a>)  <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0004, 2)
<a name="L678" href="source/drivers/net/ethernet/smsc/smc91x.h#L678">678</a> #define <a href="ident?i=TXFIFO_TEMPTY">TXFIFO_TEMPTY</a>   0x80    <b><i>// TX FIFO Empty</i></b>
<a name="L679" href="source/drivers/net/ethernet/smsc/smc91x.h#L679">679</a> <b><i></i></b>
<a name="L680" href="source/drivers/net/ethernet/smsc/smc91x.h#L680">680</a> <b><i>// RX FIFO Ports Register</i></b>
<a name="L681" href="source/drivers/net/ethernet/smsc/smc91x.h#L681">681</a> <b><i></i></b><b><i>/* BANK 2 */</i></b>
<a name="L682" href="source/drivers/net/ethernet/smsc/smc91x.h#L682">682</a> #define <a href="ident?i=RXFIFO_REG">RXFIFO_REG</a>(<a href="ident?i=lp">lp</a>)  <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0005, 2)
<a name="L683" href="source/drivers/net/ethernet/smsc/smc91x.h#L683">683</a> #define <a href="ident?i=RXFIFO_REMPTY">RXFIFO_REMPTY</a>   0x80    <b><i>// RX FIFO Empty</i></b>
<a name="L684" href="source/drivers/net/ethernet/smsc/smc91x.h#L684">684</a> <b><i></i></b>
<a name="L685" href="source/drivers/net/ethernet/smsc/smc91x.h#L685">685</a> #define <a href="ident?i=FIFO_REG">FIFO_REG</a>(<a href="ident?i=lp">lp</a>)    <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0004, 2)
<a name="L686" href="source/drivers/net/ethernet/smsc/smc91x.h#L686">686</a> 
<a name="L687" href="source/drivers/net/ethernet/smsc/smc91x.h#L687">687</a> <b><i>// Pointer Register</i></b>
<a name="L688" href="source/drivers/net/ethernet/smsc/smc91x.h#L688">688</a> <b><i></i></b><b><i>/* BANK 2 */</i></b>
<a name="L689" href="source/drivers/net/ethernet/smsc/smc91x.h#L689">689</a> #define <a href="ident?i=PTR_REG">PTR_REG</a>(<a href="ident?i=lp">lp</a>)             <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0006, 2)
<a name="L690" href="source/drivers/net/ethernet/smsc/smc91x.h#L690">690</a> #define <a href="ident?i=PTR_RCV">PTR_RCV</a>         0x8000 <b><i>// 1=Receive area, 0=Transmit area</i></b>
<a name="L691" href="source/drivers/net/ethernet/smsc/smc91x.h#L691">691</a> <b><i></i></b>#define <a href="ident?i=PTR_AUTOINC">PTR_AUTOINC</a>     0x4000 <b><i>// Auto increment the pointer on each access</i></b>
<a name="L692" href="source/drivers/net/ethernet/smsc/smc91x.h#L692">692</a> <b><i></i></b>#define <a href="ident?i=PTR_READ">PTR_READ</a>        0x2000 <b><i>// When 1 the operation is a read</i></b>
<a name="L693" href="source/drivers/net/ethernet/smsc/smc91x.h#L693">693</a> <b><i></i></b>
<a name="L694" href="source/drivers/net/ethernet/smsc/smc91x.h#L694">694</a> 
<a name="L695" href="source/drivers/net/ethernet/smsc/smc91x.h#L695">695</a> <b><i>// Data Register</i></b>
<a name="L696" href="source/drivers/net/ethernet/smsc/smc91x.h#L696">696</a> <b><i></i></b><b><i>/* BANK 2 */</i></b>
<a name="L697" href="source/drivers/net/ethernet/smsc/smc91x.h#L697">697</a> #define <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>)    <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0008, 2)
<a name="L698" href="source/drivers/net/ethernet/smsc/smc91x.h#L698">698</a> 
<a name="L699" href="source/drivers/net/ethernet/smsc/smc91x.h#L699">699</a> 
<a name="L700" href="source/drivers/net/ethernet/smsc/smc91x.h#L700">700</a> <b><i>// Interrupt Status/Acknowledge Register</i></b>
<a name="L701" href="source/drivers/net/ethernet/smsc/smc91x.h#L701">701</a> <b><i></i></b><b><i>/* BANK 2 */</i></b>
<a name="L702" href="source/drivers/net/ethernet/smsc/smc91x.h#L702">702</a> #define <a href="ident?i=INT_REG">INT_REG</a>(<a href="ident?i=lp">lp</a>)             <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x000C, 2)
<a name="L703" href="source/drivers/net/ethernet/smsc/smc91x.h#L703">703</a> 
<a name="L704" href="source/drivers/net/ethernet/smsc/smc91x.h#L704">704</a> 
<a name="L705" href="source/drivers/net/ethernet/smsc/smc91x.h#L705">705</a> <b><i>// Interrupt Mask Register</i></b>
<a name="L706" href="source/drivers/net/ethernet/smsc/smc91x.h#L706">706</a> <b><i></i></b><b><i>/* BANK 2 */</i></b>
<a name="L707" href="source/drivers/net/ethernet/smsc/smc91x.h#L707">707</a> #define <a href="ident?i=IM_REG">IM_REG</a>(<a href="ident?i=lp">lp</a>)              <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x000D, 2)
<a name="L708" href="source/drivers/net/ethernet/smsc/smc91x.h#L708">708</a> #define <a href="ident?i=IM_MDINT">IM_MDINT</a>        0x80 <b><i>// PHY MI Register 18 Interrupt</i></b>
<a name="L709" href="source/drivers/net/ethernet/smsc/smc91x.h#L709">709</a> <b><i></i></b>#define <a href="ident?i=IM_ERCV_INT">IM_ERCV_INT</a>     0x40 <b><i>// Early Receive Interrupt</i></b>
<a name="L710" href="source/drivers/net/ethernet/smsc/smc91x.h#L710">710</a> <b><i></i></b>#define <a href="ident?i=IM_EPH_INT">IM_EPH_INT</a>      0x20 <b><i>// Set by Ethernet Protocol Handler section</i></b>
<a name="L711" href="source/drivers/net/ethernet/smsc/smc91x.h#L711">711</a> <b><i></i></b>#define <a href="ident?i=IM_RX_OVRN_INT">IM_RX_OVRN_INT</a>  0x10 <b><i>// Set by Receiver Overruns</i></b>
<a name="L712" href="source/drivers/net/ethernet/smsc/smc91x.h#L712">712</a> <b><i></i></b>#define <a href="ident?i=IM_ALLOC_INT">IM_ALLOC_INT</a>    0x08 <b><i>// Set when allocation request is completed</i></b>
<a name="L713" href="source/drivers/net/ethernet/smsc/smc91x.h#L713">713</a> <b><i></i></b>#define <a href="ident?i=IM_TX_EMPTY_INT">IM_TX_EMPTY_INT</a> 0x04 <b><i>// Set if the TX FIFO goes empty</i></b>
<a name="L714" href="source/drivers/net/ethernet/smsc/smc91x.h#L714">714</a> <b><i></i></b>#define <a href="ident?i=IM_TX_INT">IM_TX_INT</a>       0x02 <b><i>// Transmit Interrupt</i></b>
<a name="L715" href="source/drivers/net/ethernet/smsc/smc91x.h#L715">715</a> <b><i></i></b>#define <a href="ident?i=IM_RCV_INT">IM_RCV_INT</a>      0x01 <b><i>// Receive Interrupt</i></b>
<a name="L716" href="source/drivers/net/ethernet/smsc/smc91x.h#L716">716</a> <b><i></i></b>
<a name="L717" href="source/drivers/net/ethernet/smsc/smc91x.h#L717">717</a> 
<a name="L718" href="source/drivers/net/ethernet/smsc/smc91x.h#L718">718</a> <b><i>// Multicast Table Registers</i></b>
<a name="L719" href="source/drivers/net/ethernet/smsc/smc91x.h#L719">719</a> <b><i></i></b><b><i>/* BANK 3 */</i></b>
<a name="L720" href="source/drivers/net/ethernet/smsc/smc91x.h#L720">720</a> #define <a href="ident?i=MCAST_REG1">MCAST_REG1</a>(<a href="ident?i=lp">lp</a>)  <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0000, 3)
<a name="L721" href="source/drivers/net/ethernet/smsc/smc91x.h#L721">721</a> #define <a href="ident?i=MCAST_REG2">MCAST_REG2</a>(<a href="ident?i=lp">lp</a>)  <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0002, 3)
<a name="L722" href="source/drivers/net/ethernet/smsc/smc91x.h#L722">722</a> #define <a href="ident?i=MCAST_REG3">MCAST_REG3</a>(<a href="ident?i=lp">lp</a>)  <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0004, 3)
<a name="L723" href="source/drivers/net/ethernet/smsc/smc91x.h#L723">723</a> #define <a href="ident?i=MCAST_REG4">MCAST_REG4</a>(<a href="ident?i=lp">lp</a>)  <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0006, 3)
<a name="L724" href="source/drivers/net/ethernet/smsc/smc91x.h#L724">724</a> 
<a name="L725" href="source/drivers/net/ethernet/smsc/smc91x.h#L725">725</a> 
<a name="L726" href="source/drivers/net/ethernet/smsc/smc91x.h#L726">726</a> <b><i>// Management Interface Register (MII)</i></b>
<a name="L727" href="source/drivers/net/ethernet/smsc/smc91x.h#L727">727</a> <b><i></i></b><b><i>/* BANK 3 */</i></b>
<a name="L728" href="source/drivers/net/ethernet/smsc/smc91x.h#L728">728</a> #define <a href="ident?i=MII_REG">MII_REG</a>(<a href="ident?i=lp">lp</a>)             <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0008, 3)
<a name="L729" href="source/drivers/net/ethernet/smsc/smc91x.h#L729">729</a> #define <a href="ident?i=MII_MSK_CRS100">MII_MSK_CRS100</a>  0x4000 <b><i>// Disables CRS100 detection during tx half dup</i></b>
<a name="L730" href="source/drivers/net/ethernet/smsc/smc91x.h#L730">730</a> <b><i></i></b>#define <a href="ident?i=MII_MDOE">MII_MDOE</a>        0x0008 <b><i>// MII Output Enable</i></b>
<a name="L731" href="source/drivers/net/ethernet/smsc/smc91x.h#L731">731</a> <b><i></i></b>#define <a href="ident?i=MII_MCLK">MII_MCLK</a>        0x0004 <b><i>// MII Clock, pin MDCLK</i></b>
<a name="L732" href="source/drivers/net/ethernet/smsc/smc91x.h#L732">732</a> <b><i></i></b>#define <a href="ident?i=MII_MDI">MII_MDI</a>         0x0002 <b><i>// MII Input, pin MDI</i></b>
<a name="L733" href="source/drivers/net/ethernet/smsc/smc91x.h#L733">733</a> <b><i></i></b>#define <a href="ident?i=MII_MDO">MII_MDO</a>         0x0001 <b><i>// MII Output, pin MDO</i></b>
<a name="L734" href="source/drivers/net/ethernet/smsc/smc91x.h#L734">734</a> <b><i></i></b>
<a name="L735" href="source/drivers/net/ethernet/smsc/smc91x.h#L735">735</a> 
<a name="L736" href="source/drivers/net/ethernet/smsc/smc91x.h#L736">736</a> <b><i>// Revision Register</i></b>
<a name="L737" href="source/drivers/net/ethernet/smsc/smc91x.h#L737">737</a> <b><i></i></b><b><i>/* BANK 3 */</i></b>
<a name="L738" href="source/drivers/net/ethernet/smsc/smc91x.h#L738">738</a> <b><i>/* ( hi: chip id   low: rev # ) */</i></b>
<a name="L739" href="source/drivers/net/ethernet/smsc/smc91x.h#L739">739</a> #define <a href="ident?i=REV_REG">REV_REG</a>(<a href="ident?i=lp">lp</a>)             <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x000A, 3)
<a name="L740" href="source/drivers/net/ethernet/smsc/smc91x.h#L740">740</a> 
<a name="L741" href="source/drivers/net/ethernet/smsc/smc91x.h#L741">741</a> 
<a name="L742" href="source/drivers/net/ethernet/smsc/smc91x.h#L742">742</a> <b><i>// Early RCV Register</i></b>
<a name="L743" href="source/drivers/net/ethernet/smsc/smc91x.h#L743">743</a> <b><i></i></b><b><i>/* BANK 3 */</i></b>
<a name="L744" href="source/drivers/net/ethernet/smsc/smc91x.h#L744">744</a> <b><i>/* this is NOT on SMC9192 */</i></b>
<a name="L745" href="source/drivers/net/ethernet/smsc/smc91x.h#L745">745</a> #define <a href="ident?i=ERCV_REG">ERCV_REG</a>(<a href="ident?i=lp">lp</a>)    <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x000C, 3)
<a name="L746" href="source/drivers/net/ethernet/smsc/smc91x.h#L746">746</a> #define <a href="ident?i=ERCV_RCV_DISCRD">ERCV_RCV_DISCRD</a> 0x0080 <b><i>// When 1 discards a packet being received</i></b>
<a name="L747" href="source/drivers/net/ethernet/smsc/smc91x.h#L747">747</a> <b><i></i></b>#define <a href="ident?i=ERCV_THRESHOLD">ERCV_THRESHOLD</a>  0x001F <b><i>// ERCV Threshold Mask</i></b>
<a name="L748" href="source/drivers/net/ethernet/smsc/smc91x.h#L748">748</a> <b><i></i></b>
<a name="L749" href="source/drivers/net/ethernet/smsc/smc91x.h#L749">749</a> 
<a name="L750" href="source/drivers/net/ethernet/smsc/smc91x.h#L750">750</a> <b><i>// External Register</i></b>
<a name="L751" href="source/drivers/net/ethernet/smsc/smc91x.h#L751">751</a> <b><i></i></b><b><i>/* BANK 7 */</i></b>
<a name="L752" href="source/drivers/net/ethernet/smsc/smc91x.h#L752">752</a> #define <a href="ident?i=EXT_REG">EXT_REG</a>(<a href="ident?i=lp">lp</a>)             <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0x0000, 7)
<a name="L753" href="source/drivers/net/ethernet/smsc/smc91x.h#L753">753</a> 
<a name="L754" href="source/drivers/net/ethernet/smsc/smc91x.h#L754">754</a> 
<a name="L755" href="source/drivers/net/ethernet/smsc/smc91x.h#L755">755</a> #define <a href="ident?i=CHIP_9192">CHIP_9192</a>       3
<a name="L756" href="source/drivers/net/ethernet/smsc/smc91x.h#L756">756</a> #define <a href="ident?i=CHIP_9194">CHIP_9194</a>       4
<a name="L757" href="source/drivers/net/ethernet/smsc/smc91x.h#L757">757</a> #define <a href="ident?i=CHIP_9195">CHIP_9195</a>       5
<a name="L758" href="source/drivers/net/ethernet/smsc/smc91x.h#L758">758</a> #define <a href="ident?i=CHIP_9196">CHIP_9196</a>       6
<a name="L759" href="source/drivers/net/ethernet/smsc/smc91x.h#L759">759</a> #define <a href="ident?i=CHIP_91100">CHIP_91100</a>      7
<a name="L760" href="source/drivers/net/ethernet/smsc/smc91x.h#L760">760</a> #define <a href="ident?i=CHIP_91100FD">CHIP_91100FD</a>    8
<a name="L761" href="source/drivers/net/ethernet/smsc/smc91x.h#L761">761</a> #define <a href="ident?i=CHIP_91111FD">CHIP_91111FD</a>    9
<a name="L762" href="source/drivers/net/ethernet/smsc/smc91x.h#L762">762</a> 
<a name="L763" href="source/drivers/net/ethernet/smsc/smc91x.h#L763">763</a> static const char * <a href="ident?i=chip_ids">chip_ids</a>[ 16 ] =  {
<a name="L764" href="source/drivers/net/ethernet/smsc/smc91x.h#L764">764</a>         <a href="ident?i=NULL">NULL</a>, <a href="ident?i=NULL">NULL</a>, <a href="ident?i=NULL">NULL</a>,
<a name="L765" href="source/drivers/net/ethernet/smsc/smc91x.h#L765">765</a>         <b><i>/* 3 */</i></b> <i>"SMC91C90/91C92"</i>,
<a name="L766" href="source/drivers/net/ethernet/smsc/smc91x.h#L766">766</a>         <b><i>/* 4 */</i></b> <i>"SMC91C94"</i>,
<a name="L767" href="source/drivers/net/ethernet/smsc/smc91x.h#L767">767</a>         <b><i>/* 5 */</i></b> <i>"SMC91C95"</i>,
<a name="L768" href="source/drivers/net/ethernet/smsc/smc91x.h#L768">768</a>         <b><i>/* 6 */</i></b> <i>"SMC91C96"</i>,
<a name="L769" href="source/drivers/net/ethernet/smsc/smc91x.h#L769">769</a>         <b><i>/* 7 */</i></b> <i>"SMC91C100"</i>,
<a name="L770" href="source/drivers/net/ethernet/smsc/smc91x.h#L770">770</a>         <b><i>/* 8 */</i></b> <i>"SMC91C100FD"</i>,
<a name="L771" href="source/drivers/net/ethernet/smsc/smc91x.h#L771">771</a>         <b><i>/* 9 */</i></b> <i>"SMC91C11xFD"</i>,
<a name="L772" href="source/drivers/net/ethernet/smsc/smc91x.h#L772">772</a>         <a href="ident?i=NULL">NULL</a>, <a href="ident?i=NULL">NULL</a>, <a href="ident?i=NULL">NULL</a>,
<a name="L773" href="source/drivers/net/ethernet/smsc/smc91x.h#L773">773</a>         <a href="ident?i=NULL">NULL</a>, <a href="ident?i=NULL">NULL</a>, <a href="ident?i=NULL">NULL</a>};
<a name="L774" href="source/drivers/net/ethernet/smsc/smc91x.h#L774">774</a> 
<a name="L775" href="source/drivers/net/ethernet/smsc/smc91x.h#L775">775</a> 
<a name="L776" href="source/drivers/net/ethernet/smsc/smc91x.h#L776">776</a> <b><i>/*</i></b>
<a name="L777" href="source/drivers/net/ethernet/smsc/smc91x.h#L777">777</a> <b><i> . Receive status bits</i></b>
<a name="L778" href="source/drivers/net/ethernet/smsc/smc91x.h#L778">778</a> <b><i>*/</i></b>
<a name="L779" href="source/drivers/net/ethernet/smsc/smc91x.h#L779">779</a> #define <a href="ident?i=RS_ALGNERR">RS_ALGNERR</a>      0x8000
<a name="L780" href="source/drivers/net/ethernet/smsc/smc91x.h#L780">780</a> #define <a href="ident?i=RS_BRODCAST">RS_BRODCAST</a>     0x4000
<a name="L781" href="source/drivers/net/ethernet/smsc/smc91x.h#L781">781</a> #define <a href="ident?i=RS_BADCRC">RS_BADCRC</a>       0x2000
<a name="L782" href="source/drivers/net/ethernet/smsc/smc91x.h#L782">782</a> #define <a href="ident?i=RS_ODDFRAME">RS_ODDFRAME</a>     0x1000
<a name="L783" href="source/drivers/net/ethernet/smsc/smc91x.h#L783">783</a> #define <a href="ident?i=RS_TOOLONG">RS_TOOLONG</a>      0x0800
<a name="L784" href="source/drivers/net/ethernet/smsc/smc91x.h#L784">784</a> #define <a href="ident?i=RS_TOOSHORT">RS_TOOSHORT</a>     0x0400
<a name="L785" href="source/drivers/net/ethernet/smsc/smc91x.h#L785">785</a> #define <a href="ident?i=RS_MULTICAST">RS_MULTICAST</a>    0x0001
<a name="L786" href="source/drivers/net/ethernet/smsc/smc91x.h#L786">786</a> #define <a href="ident?i=RS_ERRORS">RS_ERRORS</a>       (<a href="ident?i=RS_ALGNERR">RS_ALGNERR</a> | <a href="ident?i=RS_BADCRC">RS_BADCRC</a> | <a href="ident?i=RS_TOOLONG">RS_TOOLONG</a> | <a href="ident?i=RS_TOOSHORT">RS_TOOSHORT</a>)
<a name="L787" href="source/drivers/net/ethernet/smsc/smc91x.h#L787">787</a> 
<a name="L788" href="source/drivers/net/ethernet/smsc/smc91x.h#L788">788</a> 
<a name="L789" href="source/drivers/net/ethernet/smsc/smc91x.h#L789">789</a> <b><i>/*</i></b>
<a name="L790" href="source/drivers/net/ethernet/smsc/smc91x.h#L790">790</a> <b><i> * PHY IDs</i></b>
<a name="L791" href="source/drivers/net/ethernet/smsc/smc91x.h#L791">791</a> <b><i> *  LAN83C183 == LAN91C111 Internal PHY</i></b>
<a name="L792" href="source/drivers/net/ethernet/smsc/smc91x.h#L792">792</a> <b><i> */</i></b>
<a name="L793" href="source/drivers/net/ethernet/smsc/smc91x.h#L793">793</a> #define <a href="ident?i=PHY_LAN83C183">PHY_LAN83C183</a>   0x0016f840
<a name="L794" href="source/drivers/net/ethernet/smsc/smc91x.h#L794">794</a> #define <a href="ident?i=PHY_LAN83C180">PHY_LAN83C180</a>   0x02821c50
<a name="L795" href="source/drivers/net/ethernet/smsc/smc91x.h#L795">795</a> 
<a name="L796" href="source/drivers/net/ethernet/smsc/smc91x.h#L796">796</a> <b><i>/*</i></b>
<a name="L797" href="source/drivers/net/ethernet/smsc/smc91x.h#L797">797</a> <b><i> * PHY Register Addresses (LAN91C111 Internal PHY)</i></b>
<a name="L798" href="source/drivers/net/ethernet/smsc/smc91x.h#L798">798</a> <b><i> *</i></b>
<a name="L799" href="source/drivers/net/ethernet/smsc/smc91x.h#L799">799</a> <b><i> * Generic PHY registers can be found in &lt;linux/mii.h&gt;</i></b>
<a name="L800" href="source/drivers/net/ethernet/smsc/smc91x.h#L800">800</a> <b><i> *</i></b>
<a name="L801" href="source/drivers/net/ethernet/smsc/smc91x.h#L801">801</a> <b><i> * These phy registers are specific to our on-board phy.</i></b>
<a name="L802" href="source/drivers/net/ethernet/smsc/smc91x.h#L802">802</a> <b><i> */</i></b>
<a name="L803" href="source/drivers/net/ethernet/smsc/smc91x.h#L803">803</a> 
<a name="L804" href="source/drivers/net/ethernet/smsc/smc91x.h#L804">804</a> <b><i>// PHY Configuration Register 1</i></b>
<a name="L805" href="source/drivers/net/ethernet/smsc/smc91x.h#L805">805</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_REG">PHY_CFG1_REG</a>            0x10
<a name="L806" href="source/drivers/net/ethernet/smsc/smc91x.h#L806">806</a> #define <a href="ident?i=PHY_CFG1_LNKDIS">PHY_CFG1_LNKDIS</a>         0x8000  <b><i>// 1=Rx Link Detect Function disabled</i></b>
<a name="L807" href="source/drivers/net/ethernet/smsc/smc91x.h#L807">807</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_XMTDIS">PHY_CFG1_XMTDIS</a>         0x4000  <b><i>// 1=TP Transmitter Disabled</i></b>
<a name="L808" href="source/drivers/net/ethernet/smsc/smc91x.h#L808">808</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_XMTPDN">PHY_CFG1_XMTPDN</a>         0x2000  <b><i>// 1=TP Transmitter Powered Down</i></b>
<a name="L809" href="source/drivers/net/ethernet/smsc/smc91x.h#L809">809</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_BYPSCR">PHY_CFG1_BYPSCR</a>         0x0400  <b><i>// 1=Bypass scrambler/descrambler</i></b>
<a name="L810" href="source/drivers/net/ethernet/smsc/smc91x.h#L810">810</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_UNSCDS">PHY_CFG1_UNSCDS</a>         0x0200  <b><i>// 1=Unscramble Idle Reception Disable</i></b>
<a name="L811" href="source/drivers/net/ethernet/smsc/smc91x.h#L811">811</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_EQLZR">PHY_CFG1_EQLZR</a>          0x0100  <b><i>// 1=Rx Equalizer Disabled</i></b>
<a name="L812" href="source/drivers/net/ethernet/smsc/smc91x.h#L812">812</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_CABLE">PHY_CFG1_CABLE</a>          0x0080  <b><i>// 1=STP(150ohm), 0=UTP(100ohm)</i></b>
<a name="L813" href="source/drivers/net/ethernet/smsc/smc91x.h#L813">813</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_RLVL0">PHY_CFG1_RLVL0</a>          0x0040  <b><i>// 1=Rx Squelch level reduced by 4.5db</i></b>
<a name="L814" href="source/drivers/net/ethernet/smsc/smc91x.h#L814">814</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_TLVL_SHIFT">PHY_CFG1_TLVL_SHIFT</a>     2       <b><i>// Transmit Output Level Adjust</i></b>
<a name="L815" href="source/drivers/net/ethernet/smsc/smc91x.h#L815">815</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG1_TLVL_MASK">PHY_CFG1_TLVL_MASK</a>      0x003C
<a name="L816" href="source/drivers/net/ethernet/smsc/smc91x.h#L816">816</a> #define <a href="ident?i=PHY_CFG1_TRF_MASK">PHY_CFG1_TRF_MASK</a>       0x0003  <b><i>// Transmitter Rise/Fall time</i></b>
<a name="L817" href="source/drivers/net/ethernet/smsc/smc91x.h#L817">817</a> <b><i></i></b>
<a name="L818" href="source/drivers/net/ethernet/smsc/smc91x.h#L818">818</a> 
<a name="L819" href="source/drivers/net/ethernet/smsc/smc91x.h#L819">819</a> <b><i>// PHY Configuration Register 2</i></b>
<a name="L820" href="source/drivers/net/ethernet/smsc/smc91x.h#L820">820</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG2_REG">PHY_CFG2_REG</a>            0x11
<a name="L821" href="source/drivers/net/ethernet/smsc/smc91x.h#L821">821</a> #define <a href="ident?i=PHY_CFG2_APOLDIS">PHY_CFG2_APOLDIS</a>        0x0020  <b><i>// 1=Auto Polarity Correction disabled</i></b>
<a name="L822" href="source/drivers/net/ethernet/smsc/smc91x.h#L822">822</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG2_JABDIS">PHY_CFG2_JABDIS</a>         0x0010  <b><i>// 1=Jabber disabled</i></b>
<a name="L823" href="source/drivers/net/ethernet/smsc/smc91x.h#L823">823</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG2_MREG">PHY_CFG2_MREG</a>           0x0008  <b><i>// 1=Multiple register access (MII mgt)</i></b>
<a name="L824" href="source/drivers/net/ethernet/smsc/smc91x.h#L824">824</a> <b><i></i></b>#define <a href="ident?i=PHY_CFG2_INTMDIO">PHY_CFG2_INTMDIO</a>        0x0004  <b><i>// 1=Interrupt signaled with MDIO pulseo</i></b>
<a name="L825" href="source/drivers/net/ethernet/smsc/smc91x.h#L825">825</a> <b><i></i></b>
<a name="L826" href="source/drivers/net/ethernet/smsc/smc91x.h#L826">826</a> <b><i>// PHY Status Output (and Interrupt status) Register</i></b>
<a name="L827" href="source/drivers/net/ethernet/smsc/smc91x.h#L827">827</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_REG">PHY_INT_REG</a>             0x12    <b><i>// Status Output (Interrupt Status)</i></b>
<a name="L828" href="source/drivers/net/ethernet/smsc/smc91x.h#L828">828</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_INT">PHY_INT_INT</a>             0x8000  <b><i>// 1=bits have changed since last read</i></b>
<a name="L829" href="source/drivers/net/ethernet/smsc/smc91x.h#L829">829</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_LNKFAIL">PHY_INT_LNKFAIL</a>         0x4000  <b><i>// 1=Link Not detected</i></b>
<a name="L830" href="source/drivers/net/ethernet/smsc/smc91x.h#L830">830</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_LOSSSYNC">PHY_INT_LOSSSYNC</a>        0x2000  <b><i>// 1=Descrambler has lost sync</i></b>
<a name="L831" href="source/drivers/net/ethernet/smsc/smc91x.h#L831">831</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_CWRD">PHY_INT_CWRD</a>            0x1000  <b><i>// 1=Invalid 4B5B code detected on rx</i></b>
<a name="L832" href="source/drivers/net/ethernet/smsc/smc91x.h#L832">832</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_SSD">PHY_INT_SSD</a>             0x0800  <b><i>// 1=No Start Of Stream detected on rx</i></b>
<a name="L833" href="source/drivers/net/ethernet/smsc/smc91x.h#L833">833</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_ESD">PHY_INT_ESD</a>             0x0400  <b><i>// 1=No End Of Stream detected on rx</i></b>
<a name="L834" href="source/drivers/net/ethernet/smsc/smc91x.h#L834">834</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_RPOL">PHY_INT_RPOL</a>            0x0200  <b><i>// 1=Reverse Polarity detected</i></b>
<a name="L835" href="source/drivers/net/ethernet/smsc/smc91x.h#L835">835</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_JAB">PHY_INT_JAB</a>             0x0100  <b><i>// 1=Jabber detected</i></b>
<a name="L836" href="source/drivers/net/ethernet/smsc/smc91x.h#L836">836</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_SPDDET">PHY_INT_SPDDET</a>          0x0080  <b><i>// 1=100Base-TX mode, 0=10Base-T mode</i></b>
<a name="L837" href="source/drivers/net/ethernet/smsc/smc91x.h#L837">837</a> <b><i></i></b>#define <a href="ident?i=PHY_INT_DPLXDET">PHY_INT_DPLXDET</a>         0x0040  <b><i>// 1=Device in Full Duplex</i></b>
<a name="L838" href="source/drivers/net/ethernet/smsc/smc91x.h#L838">838</a> <b><i></i></b>
<a name="L839" href="source/drivers/net/ethernet/smsc/smc91x.h#L839">839</a> <b><i>// PHY Interrupt/Status Mask Register</i></b>
<a name="L840" href="source/drivers/net/ethernet/smsc/smc91x.h#L840">840</a> <b><i></i></b>#define <a href="ident?i=PHY_MASK_REG">PHY_MASK_REG</a>            0x13    <b><i>// Interrupt Mask</i></b>
<a name="L841" href="source/drivers/net/ethernet/smsc/smc91x.h#L841">841</a> <b><i></i></b><b><i>// Uses the same bit definitions as PHY_INT_REG</i></b>
<a name="L842" href="source/drivers/net/ethernet/smsc/smc91x.h#L842">842</a> <b><i></i></b>
<a name="L843" href="source/drivers/net/ethernet/smsc/smc91x.h#L843">843</a> 
<a name="L844" href="source/drivers/net/ethernet/smsc/smc91x.h#L844">844</a> <b><i>/*</i></b>
<a name="L845" href="source/drivers/net/ethernet/smsc/smc91x.h#L845">845</a> <b><i> * SMC91C96 ethernet config and status registers.</i></b>
<a name="L846" href="source/drivers/net/ethernet/smsc/smc91x.h#L846">846</a> <b><i> * These are in the "attribute" space.</i></b>
<a name="L847" href="source/drivers/net/ethernet/smsc/smc91x.h#L847">847</a> <b><i> */</i></b>
<a name="L848" href="source/drivers/net/ethernet/smsc/smc91x.h#L848">848</a> #define <a href="ident?i=ECOR">ECOR</a>                    0x8000
<a name="L849" href="source/drivers/net/ethernet/smsc/smc91x.h#L849">849</a> #define <a href="ident?i=ECOR_RESET">ECOR_RESET</a>              0x80
<a name="L850" href="source/drivers/net/ethernet/smsc/smc91x.h#L850">850</a> #define <a href="ident?i=ECOR_LEVEL_IRQ">ECOR_LEVEL_IRQ</a>          0x40
<a name="L851" href="source/drivers/net/ethernet/smsc/smc91x.h#L851">851</a> #define <a href="ident?i=ECOR_WR_ATTRIB">ECOR_WR_ATTRIB</a>          0x04
<a name="L852" href="source/drivers/net/ethernet/smsc/smc91x.h#L852">852</a> #define <a href="ident?i=ECOR_ENABLE">ECOR_ENABLE</a>             0x01
<a name="L853" href="source/drivers/net/ethernet/smsc/smc91x.h#L853">853</a> 
<a name="L854" href="source/drivers/net/ethernet/smsc/smc91x.h#L854">854</a> #define <a href="ident?i=ECSR">ECSR</a>                    0x8002
<a name="L855" href="source/drivers/net/ethernet/smsc/smc91x.h#L855">855</a> #define <a href="ident?i=ECSR_IOIS8">ECSR_IOIS8</a>              0x20
<a name="L856" href="source/drivers/net/ethernet/smsc/smc91x.h#L856">856</a> #define <a href="ident?i=ECSR_PWRDWN">ECSR_PWRDWN</a>             0x04
<a name="L857" href="source/drivers/net/ethernet/smsc/smc91x.h#L857">857</a> #define <a href="ident?i=ECSR_INT">ECSR_INT</a>                0x02
<a name="L858" href="source/drivers/net/ethernet/smsc/smc91x.h#L858">858</a> 
<a name="L859" href="source/drivers/net/ethernet/smsc/smc91x.h#L859">859</a> #define <a href="ident?i=ATTRIB_SIZE">ATTRIB_SIZE</a>             ((64*1024) &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>)
<a name="L860" href="source/drivers/net/ethernet/smsc/smc91x.h#L860">860</a> 
<a name="L861" href="source/drivers/net/ethernet/smsc/smc91x.h#L861">861</a> 
<a name="L862" href="source/drivers/net/ethernet/smsc/smc91x.h#L862">862</a> <b><i>/*</i></b>
<a name="L863" href="source/drivers/net/ethernet/smsc/smc91x.h#L863">863</a> <b><i> * Macros to abstract register access according to the data bus</i></b>
<a name="L864" href="source/drivers/net/ethernet/smsc/smc91x.h#L864">864</a> <b><i> * capabilities.  Please use those and not the in/out primitives.</i></b>
<a name="L865" href="source/drivers/net/ethernet/smsc/smc91x.h#L865">865</a> <b><i> * Note: the following macros do *not* select the bank -- this must</i></b>
<a name="L866" href="source/drivers/net/ethernet/smsc/smc91x.h#L866">866</a> <b><i> * be done separately as needed in the main code.  The SMC_REG() macro</i></b>
<a name="L867" href="source/drivers/net/ethernet/smsc/smc91x.h#L867">867</a> <b><i> * only uses the bank argument for debugging purposes (when enabled).</i></b>
<a name="L868" href="source/drivers/net/ethernet/smsc/smc91x.h#L868">868</a> <b><i> *</i></b>
<a name="L869" href="source/drivers/net/ethernet/smsc/smc91x.h#L869">869</a> <b><i> * Note: despite inline functions being safer, everything leading to this</i></b>
<a name="L870" href="source/drivers/net/ethernet/smsc/smc91x.h#L870">870</a> <b><i> * should preferably be macros to let BUG() display the line number in</i></b>
<a name="L871" href="source/drivers/net/ethernet/smsc/smc91x.h#L871">871</a> <b><i> * the core source code since we're interested in the top call site</i></b>
<a name="L872" href="source/drivers/net/ethernet/smsc/smc91x.h#L872">872</a> <b><i> * not in any inline function location.</i></b>
<a name="L873" href="source/drivers/net/ethernet/smsc/smc91x.h#L873">873</a> <b><i> */</i></b>
<a name="L874" href="source/drivers/net/ethernet/smsc/smc91x.h#L874">874</a> 
<a name="L875" href="source/drivers/net/ethernet/smsc/smc91x.h#L875">875</a> #if <a href="ident?i=SMC_DEBUG">SMC_DEBUG</a> &gt; 0
<a name="L876" href="source/drivers/net/ethernet/smsc/smc91x.h#L876">876</a> #define <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=reg">reg</a>, bank)                                  \
<a name="L877" href="source/drivers/net/ethernet/smsc/smc91x.h#L877">877</a>         ({                                                              \
<a name="L878" href="source/drivers/net/ethernet/smsc/smc91x.h#L878">878</a>                 int __b = <a href="ident?i=SMC_CURRENT_BANK">SMC_CURRENT_BANK</a>(<a href="ident?i=lp">lp</a>);                 \
<a name="L879" href="source/drivers/net/ethernet/smsc/smc91x.h#L879">879</a>                 if (<a href="ident?i=unlikely">unlikely</a>((__b &amp; ~0xf0) != (0x3300 | bank))) {       \
<a name="L880" href="source/drivers/net/ethernet/smsc/smc91x.h#L880">880</a>                         <a href="ident?i=pr_err">pr_err</a>(<i>"%s: bank reg screwed (0x%04x)\n"</i>,       \
<a name="L881" href="source/drivers/net/ethernet/smsc/smc91x.h#L881">881</a>                                <a href="ident?i=CARDNAME">CARDNAME</a>, __b);                          \
<a name="L882" href="source/drivers/net/ethernet/smsc/smc91x.h#L882">882</a>                         <a href="ident?i=BUG">BUG</a>();                                          \
<a name="L883" href="source/drivers/net/ethernet/smsc/smc91x.h#L883">883</a>                 }                                                       \
<a name="L884" href="source/drivers/net/ethernet/smsc/smc91x.h#L884">884</a>                 <a href="ident?i=reg">reg</a>&lt;&lt;<a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>;                                      \
<a name="L885" href="source/drivers/net/ethernet/smsc/smc91x.h#L885">885</a>         })
<a name="L886" href="source/drivers/net/ethernet/smsc/smc91x.h#L886">886</a> #else
<a name="L887" href="source/drivers/net/ethernet/smsc/smc91x.h#L887">887</a> #define <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=reg">reg</a>, bank)  (<a href="ident?i=reg">reg</a>&lt;&lt;<a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>)
<a name="L888" href="source/drivers/net/ethernet/smsc/smc91x.h#L888">888</a> #endif
<a name="L889" href="source/drivers/net/ethernet/smsc/smc91x.h#L889">889</a> 
<a name="L890" href="source/drivers/net/ethernet/smsc/smc91x.h#L890">890</a> <b><i>/*</i></b>
<a name="L891" href="source/drivers/net/ethernet/smsc/smc91x.h#L891">891</a> <b><i> * Hack Alert: Some setups just can't write 8 or 16 bits reliably when not</i></b>
<a name="L892" href="source/drivers/net/ethernet/smsc/smc91x.h#L892">892</a> <b><i> * aligned to a 32 bit boundary.  I tell you that does exist!</i></b>
<a name="L893" href="source/drivers/net/ethernet/smsc/smc91x.h#L893">893</a> <b><i> * Fortunately the affected register accesses can be easily worked around</i></b>
<a name="L894" href="source/drivers/net/ethernet/smsc/smc91x.h#L894">894</a> <b><i> * since we can write zeroes to the preceding 16 bits without adverse</i></b>
<a name="L895" href="source/drivers/net/ethernet/smsc/smc91x.h#L895">895</a> <b><i> * effects and use a 32-bit access.</i></b>
<a name="L896" href="source/drivers/net/ethernet/smsc/smc91x.h#L896">896</a> <b><i> *</i></b>
<a name="L897" href="source/drivers/net/ethernet/smsc/smc91x.h#L897">897</a> <b><i> * Enforce it on any 32-bit capable setup for now.</i></b>
<a name="L898" href="source/drivers/net/ethernet/smsc/smc91x.h#L898">898</a> <b><i> */</i></b>
<a name="L899" href="source/drivers/net/ethernet/smsc/smc91x.h#L899">899</a> #define <a href="ident?i=SMC_MUST_ALIGN_WRITE">SMC_MUST_ALIGN_WRITE</a>(<a href="ident?i=lp">lp</a>)        <a href="ident?i=SMC_32BIT">SMC_32BIT</a>(<a href="ident?i=lp">lp</a>)
<a name="L900" href="source/drivers/net/ethernet/smsc/smc91x.h#L900">900</a> 
<a name="L901" href="source/drivers/net/ethernet/smsc/smc91x.h#L901">901</a> #define <a href="ident?i=SMC_GET_PN">SMC_GET_PN</a>(<a href="ident?i=lp">lp</a>)                                          \
<a name="L902" href="source/drivers/net/ethernet/smsc/smc91x.h#L902">902</a>         (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>)   ? (<a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=PN_REG">PN_REG</a>(<a href="ident?i=lp">lp</a>))) \
<a name="L903" href="source/drivers/net/ethernet/smsc/smc91x.h#L903">903</a>                                 : (<a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=PN_REG">PN_REG</a>(<a href="ident?i=lp">lp</a>)) &amp; 0xFF))
<a name="L904" href="source/drivers/net/ethernet/smsc/smc91x.h#L904">904</a> 
<a name="L905" href="source/drivers/net/ethernet/smsc/smc91x.h#L905">905</a> #define <a href="ident?i=SMC_SET_PN">SMC_SET_PN</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)                                               \
<a name="L906" href="source/drivers/net/ethernet/smsc/smc91x.h#L906">906</a>         do {                                                            \
<a name="L907" href="source/drivers/net/ethernet/smsc/smc91x.h#L907">907</a>                 if (<a href="ident?i=SMC_MUST_ALIGN_WRITE">SMC_MUST_ALIGN_WRITE</a>(<a href="ident?i=lp">lp</a>))                           \
<a name="L908" href="source/drivers/net/ethernet/smsc/smc91x.h#L908">908</a>                         <a href="ident?i=SMC_outl">SMC_outl</a>((<a href="ident?i=x">x</a>)&lt;&lt;16, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 0, 2));   \
<a name="L909" href="source/drivers/net/ethernet/smsc/smc91x.h#L909">909</a>                 else if (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>))                          \
<a name="L910" href="source/drivers/net/ethernet/smsc/smc91x.h#L910">910</a>                         <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=PN_REG">PN_REG</a>(<a href="ident?i=lp">lp</a>));                \
<a name="L911" href="source/drivers/net/ethernet/smsc/smc91x.h#L911">911</a>                 else                                                    \
<a name="L912" href="source/drivers/net/ethernet/smsc/smc91x.h#L912">912</a>                         <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=PN_REG">PN_REG</a>(<a href="ident?i=lp">lp</a>));                \
<a name="L913" href="source/drivers/net/ethernet/smsc/smc91x.h#L913">913</a>         } while (0)
<a name="L914" href="source/drivers/net/ethernet/smsc/smc91x.h#L914">914</a> 
<a name="L915" href="source/drivers/net/ethernet/smsc/smc91x.h#L915">915</a> #define <a href="ident?i=SMC_GET_AR">SMC_GET_AR</a>(<a href="ident?i=lp">lp</a>)                                          \
<a name="L916" href="source/drivers/net/ethernet/smsc/smc91x.h#L916">916</a>         (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>)   ? (<a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=AR_REG">AR_REG</a>(<a href="ident?i=lp">lp</a>))) \
<a name="L917" href="source/drivers/net/ethernet/smsc/smc91x.h#L917">917</a>                                 : (<a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=PN_REG">PN_REG</a>(<a href="ident?i=lp">lp</a>)) &gt;&gt; 8))
<a name="L918" href="source/drivers/net/ethernet/smsc/smc91x.h#L918">918</a> 
<a name="L919" href="source/drivers/net/ethernet/smsc/smc91x.h#L919">919</a> #define <a href="ident?i=SMC_GET_TXFIFO">SMC_GET_TXFIFO</a>(<a href="ident?i=lp">lp</a>)                                              \
<a name="L920" href="source/drivers/net/ethernet/smsc/smc91x.h#L920">920</a>         (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>)   ? (<a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=TXFIFO_REG">TXFIFO_REG</a>(<a href="ident?i=lp">lp</a>)))     \
<a name="L921" href="source/drivers/net/ethernet/smsc/smc91x.h#L921">921</a>                                 : (<a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=TXFIFO_REG">TXFIFO_REG</a>(<a href="ident?i=lp">lp</a>)) &amp; 0xFF))
<a name="L922" href="source/drivers/net/ethernet/smsc/smc91x.h#L922">922</a> 
<a name="L923" href="source/drivers/net/ethernet/smsc/smc91x.h#L923">923</a> #define <a href="ident?i=SMC_GET_RXFIFO">SMC_GET_RXFIFO</a>(<a href="ident?i=lp">lp</a>)                                              \
<a name="L924" href="source/drivers/net/ethernet/smsc/smc91x.h#L924">924</a>         (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>)   ? (<a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=RXFIFO_REG">RXFIFO_REG</a>(<a href="ident?i=lp">lp</a>)))     \
<a name="L925" href="source/drivers/net/ethernet/smsc/smc91x.h#L925">925</a>                                 : (<a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=TXFIFO_REG">TXFIFO_REG</a>(<a href="ident?i=lp">lp</a>)) &gt;&gt; 8))
<a name="L926" href="source/drivers/net/ethernet/smsc/smc91x.h#L926">926</a> 
<a name="L927" href="source/drivers/net/ethernet/smsc/smc91x.h#L927">927</a> #define <a href="ident?i=SMC_GET_INT">SMC_GET_INT</a>(<a href="ident?i=lp">lp</a>)                                         \
<a name="L928" href="source/drivers/net/ethernet/smsc/smc91x.h#L928">928</a>         (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>)   ? (<a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=INT_REG">INT_REG</a>(<a href="ident?i=lp">lp</a>)))        \
<a name="L929" href="source/drivers/net/ethernet/smsc/smc91x.h#L929">929</a>                                 : (<a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=INT_REG">INT_REG</a>(<a href="ident?i=lp">lp</a>)) &amp; 0xFF))
<a name="L930" href="source/drivers/net/ethernet/smsc/smc91x.h#L930">930</a> 
<a name="L931" href="source/drivers/net/ethernet/smsc/smc91x.h#L931">931</a> #define <a href="ident?i=SMC_ACK_INT">SMC_ACK_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)                                              \
<a name="L932" href="source/drivers/net/ethernet/smsc/smc91x.h#L932">932</a>         do {                                                            \
<a name="L933" href="source/drivers/net/ethernet/smsc/smc91x.h#L933">933</a>                 if (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>))                                       \
<a name="L934" href="source/drivers/net/ethernet/smsc/smc91x.h#L934">934</a>                         <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=INT_REG">INT_REG</a>(<a href="ident?i=lp">lp</a>));               \
<a name="L935" href="source/drivers/net/ethernet/smsc/smc91x.h#L935">935</a>                 else {                                                  \
<a name="L936" href="source/drivers/net/ethernet/smsc/smc91x.h#L936">936</a>                         unsigned long __flags;                          \
<a name="L937" href="source/drivers/net/ethernet/smsc/smc91x.h#L937">937</a>                         int <a href="ident?i=__mask">__mask</a>;                                     \
<a name="L938" href="source/drivers/net/ethernet/smsc/smc91x.h#L938">938</a>                         <a href="ident?i=local_irq_save">local_irq_save</a>(__flags);                        \
<a name="L939" href="source/drivers/net/ethernet/smsc/smc91x.h#L939">939</a>                         <a href="ident?i=__mask">__mask</a> = <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=INT_REG">INT_REG</a>(<a href="ident?i=lp">lp</a>)) &amp; ~0xff; \
<a name="L940" href="source/drivers/net/ethernet/smsc/smc91x.h#L940">940</a>                         <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=__mask">__mask</a> | (<a href="ident?i=x">x</a>), <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=INT_REG">INT_REG</a>(<a href="ident?i=lp">lp</a>));    \
<a name="L941" href="source/drivers/net/ethernet/smsc/smc91x.h#L941">941</a>                         <a href="ident?i=local_irq_restore">local_irq_restore</a>(__flags);                     \
<a name="L942" href="source/drivers/net/ethernet/smsc/smc91x.h#L942">942</a>                 }                                                       \
<a name="L943" href="source/drivers/net/ethernet/smsc/smc91x.h#L943">943</a>         } while (0)
<a name="L944" href="source/drivers/net/ethernet/smsc/smc91x.h#L944">944</a> 
<a name="L945" href="source/drivers/net/ethernet/smsc/smc91x.h#L945">945</a> #define <a href="ident?i=SMC_GET_INT_MASK">SMC_GET_INT_MASK</a>(<a href="ident?i=lp">lp</a>)                                            \
<a name="L946" href="source/drivers/net/ethernet/smsc/smc91x.h#L946">946</a>         (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>)   ? (<a href="ident?i=SMC_inb">SMC_inb</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=IM_REG">IM_REG</a>(<a href="ident?i=lp">lp</a>))) \
<a name="L947" href="source/drivers/net/ethernet/smsc/smc91x.h#L947">947</a>                                 : (<a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=INT_REG">INT_REG</a>(<a href="ident?i=lp">lp</a>)) &gt;&gt; 8))
<a name="L948" href="source/drivers/net/ethernet/smsc/smc91x.h#L948">948</a> 
<a name="L949" href="source/drivers/net/ethernet/smsc/smc91x.h#L949">949</a> #define <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)                                 \
<a name="L950" href="source/drivers/net/ethernet/smsc/smc91x.h#L950">950</a>         do {                                                            \
<a name="L951" href="source/drivers/net/ethernet/smsc/smc91x.h#L951">951</a>                 if (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>))                                       \
<a name="L952" href="source/drivers/net/ethernet/smsc/smc91x.h#L952">952</a>                         <a href="ident?i=SMC_outb">SMC_outb</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=IM_REG">IM_REG</a>(<a href="ident?i=lp">lp</a>));                \
<a name="L953" href="source/drivers/net/ethernet/smsc/smc91x.h#L953">953</a>                 else                                                    \
<a name="L954" href="source/drivers/net/ethernet/smsc/smc91x.h#L954">954</a>                         <a href="ident?i=SMC_outw">SMC_outw</a>((<a href="ident?i=x">x</a>) &lt;&lt; 8, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=INT_REG">INT_REG</a>(<a href="ident?i=lp">lp</a>));        \
<a name="L955" href="source/drivers/net/ethernet/smsc/smc91x.h#L955">955</a>         } while (0)
<a name="L956" href="source/drivers/net/ethernet/smsc/smc91x.h#L956">956</a> 
<a name="L957" href="source/drivers/net/ethernet/smsc/smc91x.h#L957">957</a> #define <a href="ident?i=SMC_CURRENT_BANK">SMC_CURRENT_BANK</a>(<a href="ident?i=lp">lp</a>)    <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=BANK_SELECT">BANK_SELECT</a>)
<a name="L958" href="source/drivers/net/ethernet/smsc/smc91x.h#L958">958</a> 
<a name="L959" href="source/drivers/net/ethernet/smsc/smc91x.h#L959">959</a> #define <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)                                  \
<a name="L960" href="source/drivers/net/ethernet/smsc/smc91x.h#L960">960</a>         do {                                                            \
<a name="L961" href="source/drivers/net/ethernet/smsc/smc91x.h#L961">961</a>                 if (<a href="ident?i=SMC_MUST_ALIGN_WRITE">SMC_MUST_ALIGN_WRITE</a>(<a href="ident?i=lp">lp</a>))                           \
<a name="L962" href="source/drivers/net/ethernet/smsc/smc91x.h#L962">962</a>                         <a href="ident?i=SMC_outl">SMC_outl</a>((<a href="ident?i=x">x</a>)&lt;&lt;16, <a href="ident?i=ioaddr">ioaddr</a>, 12&lt;&lt;<a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>);    \
<a name="L963" href="source/drivers/net/ethernet/smsc/smc91x.h#L963">963</a>                 else                                                    \
<a name="L964" href="source/drivers/net/ethernet/smsc/smc91x.h#L964">964</a>                         <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=BANK_SELECT">BANK_SELECT</a>);               \
<a name="L965" href="source/drivers/net/ethernet/smsc/smc91x.h#L965">965</a>         } while (0)
<a name="L966" href="source/drivers/net/ethernet/smsc/smc91x.h#L966">966</a> 
<a name="L967" href="source/drivers/net/ethernet/smsc/smc91x.h#L967">967</a> #define <a href="ident?i=SMC_GET_BASE">SMC_GET_BASE</a>(<a href="ident?i=lp">lp</a>)                <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=BASE_REG">BASE_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L968" href="source/drivers/net/ethernet/smsc/smc91x.h#L968">968</a> 
<a name="L969" href="source/drivers/net/ethernet/smsc/smc91x.h#L969">969</a> #define <a href="ident?i=SMC_SET_BASE">SMC_SET_BASE</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)             <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=BASE_REG">BASE_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L970" href="source/drivers/net/ethernet/smsc/smc91x.h#L970">970</a> 
<a name="L971" href="source/drivers/net/ethernet/smsc/smc91x.h#L971">971</a> #define <a href="ident?i=SMC_GET_CONFIG">SMC_GET_CONFIG</a>(<a href="ident?i=lp">lp</a>)      <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=CONFIG_REG">CONFIG_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L972" href="source/drivers/net/ethernet/smsc/smc91x.h#L972">972</a> 
<a name="L973" href="source/drivers/net/ethernet/smsc/smc91x.h#L973">973</a> #define <a href="ident?i=SMC_SET_CONFIG">SMC_SET_CONFIG</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)   <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=CONFIG_REG">CONFIG_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L974" href="source/drivers/net/ethernet/smsc/smc91x.h#L974">974</a> 
<a name="L975" href="source/drivers/net/ethernet/smsc/smc91x.h#L975">975</a> #define <a href="ident?i=SMC_GET_COUNTER">SMC_GET_COUNTER</a>(<a href="ident?i=lp">lp</a>)     <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=COUNTER_REG">COUNTER_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L976" href="source/drivers/net/ethernet/smsc/smc91x.h#L976">976</a> 
<a name="L977" href="source/drivers/net/ethernet/smsc/smc91x.h#L977">977</a> #define <a href="ident?i=SMC_GET_CTL">SMC_GET_CTL</a>(<a href="ident?i=lp">lp</a>)         <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=CTL_REG">CTL_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L978" href="source/drivers/net/ethernet/smsc/smc91x.h#L978">978</a> 
<a name="L979" href="source/drivers/net/ethernet/smsc/smc91x.h#L979">979</a> #define <a href="ident?i=SMC_SET_CTL">SMC_SET_CTL</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)              <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=CTL_REG">CTL_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L980" href="source/drivers/net/ethernet/smsc/smc91x.h#L980">980</a> 
<a name="L981" href="source/drivers/net/ethernet/smsc/smc91x.h#L981">981</a> #define <a href="ident?i=SMC_GET_MII">SMC_GET_MII</a>(<a href="ident?i=lp">lp</a>)         <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MII_REG">MII_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L982" href="source/drivers/net/ethernet/smsc/smc91x.h#L982">982</a> 
<a name="L983" href="source/drivers/net/ethernet/smsc/smc91x.h#L983">983</a> #define <a href="ident?i=SMC_GET_GP">SMC_GET_GP</a>(<a href="ident?i=lp">lp</a>)          <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=GP_REG">GP_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L984" href="source/drivers/net/ethernet/smsc/smc91x.h#L984">984</a> 
<a name="L985" href="source/drivers/net/ethernet/smsc/smc91x.h#L985">985</a> #define <a href="ident?i=SMC_SET_GP">SMC_SET_GP</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)                                               \
<a name="L986" href="source/drivers/net/ethernet/smsc/smc91x.h#L986">986</a>         do {                                                            \
<a name="L987" href="source/drivers/net/ethernet/smsc/smc91x.h#L987">987</a>                 if (<a href="ident?i=SMC_MUST_ALIGN_WRITE">SMC_MUST_ALIGN_WRITE</a>(<a href="ident?i=lp">lp</a>))                           \
<a name="L988" href="source/drivers/net/ethernet/smsc/smc91x.h#L988">988</a>                         <a href="ident?i=SMC_outl">SMC_outl</a>((<a href="ident?i=x">x</a>)&lt;&lt;16, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 8, 1));   \
<a name="L989" href="source/drivers/net/ethernet/smsc/smc91x.h#L989">989</a>                 else                                                    \
<a name="L990" href="source/drivers/net/ethernet/smsc/smc91x.h#L990">990</a>                         <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=GP_REG">GP_REG</a>(<a href="ident?i=lp">lp</a>));                \
<a name="L991" href="source/drivers/net/ethernet/smsc/smc91x.h#L991">991</a>         } while (0)
<a name="L992" href="source/drivers/net/ethernet/smsc/smc91x.h#L992">992</a> 
<a name="L993" href="source/drivers/net/ethernet/smsc/smc91x.h#L993">993</a> #define <a href="ident?i=SMC_SET_MII">SMC_SET_MII</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)              <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MII_REG">MII_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L994" href="source/drivers/net/ethernet/smsc/smc91x.h#L994">994</a> 
<a name="L995" href="source/drivers/net/ethernet/smsc/smc91x.h#L995">995</a> #define <a href="ident?i=SMC_GET_MIR">SMC_GET_MIR</a>(<a href="ident?i=lp">lp</a>)         <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MIR_REG">MIR_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L996" href="source/drivers/net/ethernet/smsc/smc91x.h#L996">996</a> 
<a name="L997" href="source/drivers/net/ethernet/smsc/smc91x.h#L997">997</a> #define <a href="ident?i=SMC_SET_MIR">SMC_SET_MIR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)              <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MIR_REG">MIR_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L998" href="source/drivers/net/ethernet/smsc/smc91x.h#L998">998</a> 
<a name="L999" href="source/drivers/net/ethernet/smsc/smc91x.h#L999">999</a> #define <a href="ident?i=SMC_GET_MMU_CMD">SMC_GET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>)     <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MMU_CMD_REG">MMU_CMD_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1000" href="source/drivers/net/ethernet/smsc/smc91x.h#L1000">1000</a> 
<a name="L1001" href="source/drivers/net/ethernet/smsc/smc91x.h#L1001">1001</a> #define <a href="ident?i=SMC_SET_MMU_CMD">SMC_SET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)  <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MMU_CMD_REG">MMU_CMD_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1002" href="source/drivers/net/ethernet/smsc/smc91x.h#L1002">1002</a> 
<a name="L1003" href="source/drivers/net/ethernet/smsc/smc91x.h#L1003">1003</a> #define <a href="ident?i=SMC_GET_FIFO">SMC_GET_FIFO</a>(<a href="ident?i=lp">lp</a>)                <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=FIFO_REG">FIFO_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1004" href="source/drivers/net/ethernet/smsc/smc91x.h#L1004">1004</a> 
<a name="L1005" href="source/drivers/net/ethernet/smsc/smc91x.h#L1005">1005</a> #define <a href="ident?i=SMC_GET_PTR">SMC_GET_PTR</a>(<a href="ident?i=lp">lp</a>)         <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=PTR_REG">PTR_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1006" href="source/drivers/net/ethernet/smsc/smc91x.h#L1006">1006</a> 
<a name="L1007" href="source/drivers/net/ethernet/smsc/smc91x.h#L1007">1007</a> #define <a href="ident?i=SMC_SET_PTR">SMC_SET_PTR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)                                              \
<a name="L1008" href="source/drivers/net/ethernet/smsc/smc91x.h#L1008">1008</a>         do {                                                            \
<a name="L1009" href="source/drivers/net/ethernet/smsc/smc91x.h#L1009">1009</a>                 if (<a href="ident?i=SMC_MUST_ALIGN_WRITE">SMC_MUST_ALIGN_WRITE</a>(<a href="ident?i=lp">lp</a>))                           \
<a name="L1010" href="source/drivers/net/ethernet/smsc/smc91x.h#L1010">1010</a>                         <a href="ident?i=SMC_outl">SMC_outl</a>((<a href="ident?i=x">x</a>)&lt;&lt;16, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 4, 2));   \
<a name="L1011" href="source/drivers/net/ethernet/smsc/smc91x.h#L1011">1011</a>                 else                                                    \
<a name="L1012" href="source/drivers/net/ethernet/smsc/smc91x.h#L1012">1012</a>                         <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=PTR_REG">PTR_REG</a>(<a href="ident?i=lp">lp</a>));               \
<a name="L1013" href="source/drivers/net/ethernet/smsc/smc91x.h#L1013">1013</a>         } while (0)
<a name="L1014" href="source/drivers/net/ethernet/smsc/smc91x.h#L1014">1014</a> 
<a name="L1015" href="source/drivers/net/ethernet/smsc/smc91x.h#L1015">1015</a> #define <a href="ident?i=SMC_GET_EPH_STATUS">SMC_GET_EPH_STATUS</a>(<a href="ident?i=lp">lp</a>)  <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=EPH_STATUS_REG">EPH_STATUS_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1016" href="source/drivers/net/ethernet/smsc/smc91x.h#L1016">1016</a> 
<a name="L1017" href="source/drivers/net/ethernet/smsc/smc91x.h#L1017">1017</a> #define <a href="ident?i=SMC_GET_RCR">SMC_GET_RCR</a>(<a href="ident?i=lp">lp</a>)         <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=RCR_REG">RCR_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1018" href="source/drivers/net/ethernet/smsc/smc91x.h#L1018">1018</a> 
<a name="L1019" href="source/drivers/net/ethernet/smsc/smc91x.h#L1019">1019</a> #define <a href="ident?i=SMC_SET_RCR">SMC_SET_RCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)              <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=RCR_REG">RCR_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1020" href="source/drivers/net/ethernet/smsc/smc91x.h#L1020">1020</a> 
<a name="L1021" href="source/drivers/net/ethernet/smsc/smc91x.h#L1021">1021</a> #define <a href="ident?i=SMC_GET_REV">SMC_GET_REV</a>(<a href="ident?i=lp">lp</a>)         <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=REV_REG">REV_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1022" href="source/drivers/net/ethernet/smsc/smc91x.h#L1022">1022</a> 
<a name="L1023" href="source/drivers/net/ethernet/smsc/smc91x.h#L1023">1023</a> #define <a href="ident?i=SMC_GET_RPC">SMC_GET_RPC</a>(<a href="ident?i=lp">lp</a>)         <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=RPC_REG">RPC_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1024" href="source/drivers/net/ethernet/smsc/smc91x.h#L1024">1024</a> 
<a name="L1025" href="source/drivers/net/ethernet/smsc/smc91x.h#L1025">1025</a> #define <a href="ident?i=SMC_SET_RPC">SMC_SET_RPC</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)                                              \
<a name="L1026" href="source/drivers/net/ethernet/smsc/smc91x.h#L1026">1026</a>         do {                                                            \
<a name="L1027" href="source/drivers/net/ethernet/smsc/smc91x.h#L1027">1027</a>                 if (<a href="ident?i=SMC_MUST_ALIGN_WRITE">SMC_MUST_ALIGN_WRITE</a>(<a href="ident?i=lp">lp</a>))                           \
<a name="L1028" href="source/drivers/net/ethernet/smsc/smc91x.h#L1028">1028</a>                         <a href="ident?i=SMC_outl">SMC_outl</a>((<a href="ident?i=x">x</a>)&lt;&lt;16, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=SMC_REG">SMC_REG</a>(<a href="ident?i=lp">lp</a>, 8, 0));   \
<a name="L1029" href="source/drivers/net/ethernet/smsc/smc91x.h#L1029">1029</a>                 else                                                    \
<a name="L1030" href="source/drivers/net/ethernet/smsc/smc91x.h#L1030">1030</a>                         <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=RPC_REG">RPC_REG</a>(<a href="ident?i=lp">lp</a>));               \
<a name="L1031" href="source/drivers/net/ethernet/smsc/smc91x.h#L1031">1031</a>         } while (0)
<a name="L1032" href="source/drivers/net/ethernet/smsc/smc91x.h#L1032">1032</a> 
<a name="L1033" href="source/drivers/net/ethernet/smsc/smc91x.h#L1033">1033</a> #define <a href="ident?i=SMC_GET_TCR">SMC_GET_TCR</a>(<a href="ident?i=lp">lp</a>)         <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=TCR_REG">TCR_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1034" href="source/drivers/net/ethernet/smsc/smc91x.h#L1034">1034</a> 
<a name="L1035" href="source/drivers/net/ethernet/smsc/smc91x.h#L1035">1035</a> #define <a href="ident?i=SMC_SET_TCR">SMC_SET_TCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)              <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=x">x</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=TCR_REG">TCR_REG</a>(<a href="ident?i=lp">lp</a>))
<a name="L1036" href="source/drivers/net/ethernet/smsc/smc91x.h#L1036">1036</a> 
<a name="L1037" href="source/drivers/net/ethernet/smsc/smc91x.h#L1037">1037</a> #ifndef <a href="ident?i=SMC_GET_MAC_ADDR">SMC_GET_MAC_ADDR</a>
<a name="L1038" href="source/drivers/net/ethernet/smsc/smc91x.h#L1038">1038</a> #define <a href="ident?i=SMC_GET_MAC_ADDR">SMC_GET_MAC_ADDR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=addr">addr</a>)                                      \
<a name="L1039" href="source/drivers/net/ethernet/smsc/smc91x.h#L1039">1039</a>         do {                                                            \
<a name="L1040" href="source/drivers/net/ethernet/smsc/smc91x.h#L1040">1040</a>                 unsigned int __v;                                       \
<a name="L1041" href="source/drivers/net/ethernet/smsc/smc91x.h#L1041">1041</a>                 __v = <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=ADDR0_REG">ADDR0_REG</a>(<a href="ident?i=lp">lp</a>));                   \
<a name="L1042" href="source/drivers/net/ethernet/smsc/smc91x.h#L1042">1042</a>                 <a href="ident?i=addr">addr</a>[0] = __v; <a href="ident?i=addr">addr</a>[1] = __v &gt;&gt; 8;                      \
<a name="L1043" href="source/drivers/net/ethernet/smsc/smc91x.h#L1043">1043</a>                 __v = <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=ADDR1_REG">ADDR1_REG</a>(<a href="ident?i=lp">lp</a>));                   \
<a name="L1044" href="source/drivers/net/ethernet/smsc/smc91x.h#L1044">1044</a>                 <a href="ident?i=addr">addr</a>[2] = __v; <a href="ident?i=addr">addr</a>[3] = __v &gt;&gt; 8;                      \
<a name="L1045" href="source/drivers/net/ethernet/smsc/smc91x.h#L1045">1045</a>                 __v = <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=ADDR2_REG">ADDR2_REG</a>(<a href="ident?i=lp">lp</a>));                   \
<a name="L1046" href="source/drivers/net/ethernet/smsc/smc91x.h#L1046">1046</a>                 <a href="ident?i=addr">addr</a>[4] = __v; <a href="ident?i=addr">addr</a>[5] = __v &gt;&gt; 8;                      \
<a name="L1047" href="source/drivers/net/ethernet/smsc/smc91x.h#L1047">1047</a>         } while (0)
<a name="L1048" href="source/drivers/net/ethernet/smsc/smc91x.h#L1048">1048</a> #endif
<a name="L1049" href="source/drivers/net/ethernet/smsc/smc91x.h#L1049">1049</a> 
<a name="L1050" href="source/drivers/net/ethernet/smsc/smc91x.h#L1050">1050</a> #define <a href="ident?i=SMC_SET_MAC_ADDR">SMC_SET_MAC_ADDR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=addr">addr</a>)                                      \
<a name="L1051" href="source/drivers/net/ethernet/smsc/smc91x.h#L1051">1051</a>         do {                                                            \
<a name="L1052" href="source/drivers/net/ethernet/smsc/smc91x.h#L1052">1052</a>                 <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=addr">addr</a>[0]|(<a href="ident?i=addr">addr</a>[1] &lt;&lt; 8), <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=ADDR0_REG">ADDR0_REG</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1053" href="source/drivers/net/ethernet/smsc/smc91x.h#L1053">1053</a>                 <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=addr">addr</a>[2]|(<a href="ident?i=addr">addr</a>[3] &lt;&lt; 8), <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=ADDR1_REG">ADDR1_REG</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1054" href="source/drivers/net/ethernet/smsc/smc91x.h#L1054">1054</a>                 <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=addr">addr</a>[4]|(<a href="ident?i=addr">addr</a>[5] &lt;&lt; 8), <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=ADDR2_REG">ADDR2_REG</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1055" href="source/drivers/net/ethernet/smsc/smc91x.h#L1055">1055</a>         } while (0)
<a name="L1056" href="source/drivers/net/ethernet/smsc/smc91x.h#L1056">1056</a> 
<a name="L1057" href="source/drivers/net/ethernet/smsc/smc91x.h#L1057">1057</a> #define <a href="ident?i=SMC_SET_MCAST">SMC_SET_MCAST</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>)                                            \
<a name="L1058" href="source/drivers/net/ethernet/smsc/smc91x.h#L1058">1058</a>         do {                                                            \
<a name="L1059" href="source/drivers/net/ethernet/smsc/smc91x.h#L1059">1059</a>                 const unsigned char *<a href="ident?i=mt">mt</a> = (<a href="ident?i=x">x</a>);                          \
<a name="L1060" href="source/drivers/net/ethernet/smsc/smc91x.h#L1060">1060</a>                 <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=mt">mt</a>[0] | (<a href="ident?i=mt">mt</a>[1] &lt;&lt; 8), <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MCAST_REG1">MCAST_REG1</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1061" href="source/drivers/net/ethernet/smsc/smc91x.h#L1061">1061</a>                 <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=mt">mt</a>[2] | (<a href="ident?i=mt">mt</a>[3] &lt;&lt; 8), <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MCAST_REG2">MCAST_REG2</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1062" href="source/drivers/net/ethernet/smsc/smc91x.h#L1062">1062</a>                 <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=mt">mt</a>[4] | (<a href="ident?i=mt">mt</a>[5] &lt;&lt; 8), <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MCAST_REG3">MCAST_REG3</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1063" href="source/drivers/net/ethernet/smsc/smc91x.h#L1063">1063</a>                 <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=mt">mt</a>[6] | (<a href="ident?i=mt">mt</a>[7] &lt;&lt; 8), <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=MCAST_REG4">MCAST_REG4</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1064" href="source/drivers/net/ethernet/smsc/smc91x.h#L1064">1064</a>         } while (0)
<a name="L1065" href="source/drivers/net/ethernet/smsc/smc91x.h#L1065">1065</a> 
<a name="L1066" href="source/drivers/net/ethernet/smsc/smc91x.h#L1066">1066</a> #define <a href="ident?i=SMC_PUT_PKT_HDR">SMC_PUT_PKT_HDR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=status">status</a>, <a href="ident?i=length">length</a>)                             \
<a name="L1067" href="source/drivers/net/ethernet/smsc/smc91x.h#L1067">1067</a>         do {                                                            \
<a name="L1068" href="source/drivers/net/ethernet/smsc/smc91x.h#L1068">1068</a>                 if (<a href="ident?i=SMC_32BIT">SMC_32BIT</a>(<a href="ident?i=lp">lp</a>))                                      \
<a name="L1069" href="source/drivers/net/ethernet/smsc/smc91x.h#L1069">1069</a>                         <a href="ident?i=SMC_outl">SMC_outl</a>((<a href="ident?i=status">status</a>) | (<a href="ident?i=length">length</a>)&lt;&lt;16, <a href="ident?i=ioaddr">ioaddr</a>,       \
<a name="L1070" href="source/drivers/net/ethernet/smsc/smc91x.h#L1070">1070</a>                                  <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>));                 \
<a name="L1071" href="source/drivers/net/ethernet/smsc/smc91x.h#L1071">1071</a>                 else {                                                  \
<a name="L1072" href="source/drivers/net/ethernet/smsc/smc91x.h#L1072">1072</a>                         <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=status">status</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1073" href="source/drivers/net/ethernet/smsc/smc91x.h#L1073">1073</a>                         <a href="ident?i=SMC_outw">SMC_outw</a>(<a href="ident?i=length">length</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1074" href="source/drivers/net/ethernet/smsc/smc91x.h#L1074">1074</a>                 }                                                       \
<a name="L1075" href="source/drivers/net/ethernet/smsc/smc91x.h#L1075">1075</a>         } while (0)
<a name="L1076" href="source/drivers/net/ethernet/smsc/smc91x.h#L1076">1076</a> 
<a name="L1077" href="source/drivers/net/ethernet/smsc/smc91x.h#L1077">1077</a> #define <a href="ident?i=SMC_GET_PKT_HDR">SMC_GET_PKT_HDR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=status">status</a>, <a href="ident?i=length">length</a>)                             \
<a name="L1078" href="source/drivers/net/ethernet/smsc/smc91x.h#L1078">1078</a>         do {                                                            \
<a name="L1079" href="source/drivers/net/ethernet/smsc/smc91x.h#L1079">1079</a>                 if (<a href="ident?i=SMC_32BIT">SMC_32BIT</a>(<a href="ident?i=lp">lp</a>)) {                            \
<a name="L1080" href="source/drivers/net/ethernet/smsc/smc91x.h#L1080">1080</a>                         unsigned int <a href="ident?i=__val">__val</a> = <a href="ident?i=SMC_inl">SMC_inl</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>)); \
<a name="L1081" href="source/drivers/net/ethernet/smsc/smc91x.h#L1081">1081</a>                         (<a href="ident?i=status">status</a>) = <a href="ident?i=__val">__val</a> &amp; 0xffff;                      \
<a name="L1082" href="source/drivers/net/ethernet/smsc/smc91x.h#L1082">1082</a>                         (<a href="ident?i=length">length</a>) = <a href="ident?i=__val">__val</a> &gt;&gt; 16;                         \
<a name="L1083" href="source/drivers/net/ethernet/smsc/smc91x.h#L1083">1083</a>                 } else {                                                \
<a name="L1084" href="source/drivers/net/ethernet/smsc/smc91x.h#L1084">1084</a>                         (<a href="ident?i=status">status</a>) = <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>));       \
<a name="L1085" href="source/drivers/net/ethernet/smsc/smc91x.h#L1085">1085</a>                         (<a href="ident?i=length">length</a>) = <a href="ident?i=SMC_inw">SMC_inw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>));       \
<a name="L1086" href="source/drivers/net/ethernet/smsc/smc91x.h#L1086">1086</a>                 }                                                       \
<a name="L1087" href="source/drivers/net/ethernet/smsc/smc91x.h#L1087">1087</a>         } while (0)
<a name="L1088" href="source/drivers/net/ethernet/smsc/smc91x.h#L1088">1088</a> 
<a name="L1089" href="source/drivers/net/ethernet/smsc/smc91x.h#L1089">1089</a> #define <a href="ident?i=SMC_PUSH_DATA">SMC_PUSH_DATA</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)                                 \
<a name="L1090" href="source/drivers/net/ethernet/smsc/smc91x.h#L1090">1090</a>         do {                                                            \
<a name="L1091" href="source/drivers/net/ethernet/smsc/smc91x.h#L1091">1091</a>                 if (<a href="ident?i=SMC_32BIT">SMC_32BIT</a>(<a href="ident?i=lp">lp</a>)) {                            \
<a name="L1092" href="source/drivers/net/ethernet/smsc/smc91x.h#L1092">1092</a>                         void *<a href="ident?i=__ptr">__ptr</a> = (<a href="ident?i=p">p</a>);                              \
<a name="L1093" href="source/drivers/net/ethernet/smsc/smc91x.h#L1093">1093</a>                         int __len = (<a href="ident?i=l">l</a>);                                \
<a name="L1094" href="source/drivers/net/ethernet/smsc/smc91x.h#L1094">1094</a>                         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=__ioaddr">__ioaddr</a> = <a href="ident?i=ioaddr">ioaddr</a>;                \
<a name="L1095" href="source/drivers/net/ethernet/smsc/smc91x.h#L1095">1095</a>                         if (__len &gt;= 2 &amp;&amp; (unsigned long)<a href="ident?i=__ptr">__ptr</a> &amp; 2) {   \
<a name="L1096" href="source/drivers/net/ethernet/smsc/smc91x.h#L1096">1096</a>                                 __len -= 2;                             \
<a name="L1097" href="source/drivers/net/ethernet/smsc/smc91x.h#L1097">1097</a>                                 <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>), <a href="ident?i=__ptr">__ptr</a>, 1); \
<a name="L1098" href="source/drivers/net/ethernet/smsc/smc91x.h#L1098">1098</a>                                 <a href="ident?i=__ptr">__ptr</a> += 2;                             \
<a name="L1099" href="source/drivers/net/ethernet/smsc/smc91x.h#L1099">1099</a>                         }                                               \
<a name="L1100" href="source/drivers/net/ethernet/smsc/smc91x.h#L1100">1100</a>                         if (<a href="ident?i=SMC_CAN_USE_DATACS">SMC_CAN_USE_DATACS</a> &amp;&amp; <a href="ident?i=lp">lp</a>-&gt;datacs)           \
<a name="L1101" href="source/drivers/net/ethernet/smsc/smc91x.h#L1101">1101</a>                                 <a href="ident?i=__ioaddr">__ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;datacs;                  \
<a name="L1102" href="source/drivers/net/ethernet/smsc/smc91x.h#L1102">1102</a>                         <a href="ident?i=SMC_outsl">SMC_outsl</a>(<a href="ident?i=__ioaddr">__ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>), <a href="ident?i=__ptr">__ptr</a>, __len&gt;&gt;2); \
<a name="L1103" href="source/drivers/net/ethernet/smsc/smc91x.h#L1103">1103</a>                         if (__len &amp; 2) {                                \
<a name="L1104" href="source/drivers/net/ethernet/smsc/smc91x.h#L1104">1104</a>                                 <a href="ident?i=__ptr">__ptr</a> += (__len &amp; ~3);                  \
<a name="L1105" href="source/drivers/net/ethernet/smsc/smc91x.h#L1105">1105</a>                                 <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>), <a href="ident?i=__ptr">__ptr</a>, 1); \
<a name="L1106" href="source/drivers/net/ethernet/smsc/smc91x.h#L1106">1106</a>                         }                                               \
<a name="L1107" href="source/drivers/net/ethernet/smsc/smc91x.h#L1107">1107</a>                 } else if (<a href="ident?i=SMC_16BIT">SMC_16BIT</a>(<a href="ident?i=lp">lp</a>))                               \
<a name="L1108" href="source/drivers/net/ethernet/smsc/smc91x.h#L1108">1108</a>                         <a href="ident?i=SMC_outsw">SMC_outsw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>), <a href="ident?i=p">p</a>, (<a href="ident?i=l">l</a>) &gt;&gt; 1);   \
<a name="L1109" href="source/drivers/net/ethernet/smsc/smc91x.h#L1109">1109</a>                 else if (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>))                          \
<a name="L1110" href="source/drivers/net/ethernet/smsc/smc91x.h#L1110">1110</a>                         <a href="ident?i=SMC_outsb">SMC_outsb</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>);  \
<a name="L1111" href="source/drivers/net/ethernet/smsc/smc91x.h#L1111">1111</a>         } while (0)
<a name="L1112" href="source/drivers/net/ethernet/smsc/smc91x.h#L1112">1112</a> 
<a name="L1113" href="source/drivers/net/ethernet/smsc/smc91x.h#L1113">1113</a> #define <a href="ident?i=SMC_PULL_DATA">SMC_PULL_DATA</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>)                                 \
<a name="L1114" href="source/drivers/net/ethernet/smsc/smc91x.h#L1114">1114</a>         do {                                                            \
<a name="L1115" href="source/drivers/net/ethernet/smsc/smc91x.h#L1115">1115</a>                 if (<a href="ident?i=SMC_32BIT">SMC_32BIT</a>(<a href="ident?i=lp">lp</a>)) {                            \
<a name="L1116" href="source/drivers/net/ethernet/smsc/smc91x.h#L1116">1116</a>                         void *<a href="ident?i=__ptr">__ptr</a> = (<a href="ident?i=p">p</a>);                              \
<a name="L1117" href="source/drivers/net/ethernet/smsc/smc91x.h#L1117">1117</a>                         int __len = (<a href="ident?i=l">l</a>);                                \
<a name="L1118" href="source/drivers/net/ethernet/smsc/smc91x.h#L1118">1118</a>                         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=__ioaddr">__ioaddr</a> = <a href="ident?i=ioaddr">ioaddr</a>;                \
<a name="L1119" href="source/drivers/net/ethernet/smsc/smc91x.h#L1119">1119</a>                         if ((unsigned long)<a href="ident?i=__ptr">__ptr</a> &amp; 2) {                 \
<a name="L1120" href="source/drivers/net/ethernet/smsc/smc91x.h#L1120">1120</a>                                 <b><i>/*                                      \</i></b>
<a name="L1121" href="source/drivers/net/ethernet/smsc/smc91x.h#L1121">1121</a> <b><i>                                 * We want 32bit alignment here.        \</i></b>
<a name="L1122" href="source/drivers/net/ethernet/smsc/smc91x.h#L1122">1122</a> <b><i>                                 * Since some buses perform a full      \</i></b>
<a name="L1123" href="source/drivers/net/ethernet/smsc/smc91x.h#L1123">1123</a> <b><i>                                 * 32bit fetch even for 16bit data      \</i></b>
<a name="L1124" href="source/drivers/net/ethernet/smsc/smc91x.h#L1124">1124</a> <b><i>                                 * we can't use SMC_inw() here.         \</i></b>
<a name="L1125" href="source/drivers/net/ethernet/smsc/smc91x.h#L1125">1125</a> <b><i>                                 * Back both source (on-chip) and       \</i></b>
<a name="L1126" href="source/drivers/net/ethernet/smsc/smc91x.h#L1126">1126</a> <b><i>                                 * destination pointers of 2 bytes.     \</i></b>
<a name="L1127" href="source/drivers/net/ethernet/smsc/smc91x.h#L1127">1127</a> <b><i>                                 * This is possible since the call to   \</i></b>
<a name="L1128" href="source/drivers/net/ethernet/smsc/smc91x.h#L1128">1128</a> <b><i>                                 * SMC_GET_PKT_HDR() already advanced   \</i></b>
<a name="L1129" href="source/drivers/net/ethernet/smsc/smc91x.h#L1129">1129</a> <b><i>                                 * the source pointer of 4 bytes, and   \</i></b>
<a name="L1130" href="source/drivers/net/ethernet/smsc/smc91x.h#L1130">1130</a> <b><i>                                 * the skb_reserve(skb, 2) advanced     \</i></b>
<a name="L1131" href="source/drivers/net/ethernet/smsc/smc91x.h#L1131">1131</a> <b><i>                                 * the destination pointer of 2 bytes.  \</i></b>
<a name="L1132" href="source/drivers/net/ethernet/smsc/smc91x.h#L1132">1132</a> <b><i>                                 */</i></b>                                     \
<a name="L1133" href="source/drivers/net/ethernet/smsc/smc91x.h#L1133">1133</a>                                 <a href="ident?i=__ptr">__ptr</a> -= 2;                             \
<a name="L1134" href="source/drivers/net/ethernet/smsc/smc91x.h#L1134">1134</a>                                 __len += 2;                             \
<a name="L1135" href="source/drivers/net/ethernet/smsc/smc91x.h#L1135">1135</a>                                 <a href="ident?i=SMC_SET_PTR">SMC_SET_PTR</a>(<a href="ident?i=lp">lp</a>,                 \
<a name="L1136" href="source/drivers/net/ethernet/smsc/smc91x.h#L1136">1136</a>                                         2|<a href="ident?i=PTR_READ">PTR_READ</a>|<a href="ident?i=PTR_RCV">PTR_RCV</a>|<a href="ident?i=PTR_AUTOINC">PTR_AUTOINC</a>); \
<a name="L1137" href="source/drivers/net/ethernet/smsc/smc91x.h#L1137">1137</a>                         }                                               \
<a name="L1138" href="source/drivers/net/ethernet/smsc/smc91x.h#L1138">1138</a>                         if (<a href="ident?i=SMC_CAN_USE_DATACS">SMC_CAN_USE_DATACS</a> &amp;&amp; <a href="ident?i=lp">lp</a>-&gt;datacs)           \
<a name="L1139" href="source/drivers/net/ethernet/smsc/smc91x.h#L1139">1139</a>                                 <a href="ident?i=__ioaddr">__ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;datacs;                  \
<a name="L1140" href="source/drivers/net/ethernet/smsc/smc91x.h#L1140">1140</a>                         __len += 2;                                     \
<a name="L1141" href="source/drivers/net/ethernet/smsc/smc91x.h#L1141">1141</a>                         <a href="ident?i=SMC_insl">SMC_insl</a>(<a href="ident?i=__ioaddr">__ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>), <a href="ident?i=__ptr">__ptr</a>, __len&gt;&gt;2); \
<a name="L1142" href="source/drivers/net/ethernet/smsc/smc91x.h#L1142">1142</a>                 } else if (<a href="ident?i=SMC_16BIT">SMC_16BIT</a>(<a href="ident?i=lp">lp</a>))                               \
<a name="L1143" href="source/drivers/net/ethernet/smsc/smc91x.h#L1143">1143</a>                         <a href="ident?i=SMC_insw">SMC_insw</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>), <a href="ident?i=p">p</a>, (<a href="ident?i=l">l</a>) &gt;&gt; 1);    \
<a name="L1144" href="source/drivers/net/ethernet/smsc/smc91x.h#L1144">1144</a>                 else if (<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>))                          \
<a name="L1145" href="source/drivers/net/ethernet/smsc/smc91x.h#L1145">1145</a>                         <a href="ident?i=SMC_insb">SMC_insb</a>(<a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>), <a href="ident?i=p">p</a>, <a href="ident?i=l">l</a>);           \
<a name="L1146" href="source/drivers/net/ethernet/smsc/smc91x.h#L1146">1146</a>         } while (0)
<a name="L1147" href="source/drivers/net/ethernet/smsc/smc91x.h#L1147">1147</a> 
<a name="L1148" href="source/drivers/net/ethernet/smsc/smc91x.h#L1148">1148</a> #endif  <b><i>/* _SMC91X_H_ */</i></b>
<a name="L1149" href="source/drivers/net/ethernet/smsc/smc91x.h#L1149">1149</a> </pre></div><p>
This page was automatically generated by <a href="https://sourceforge.net/projects/lxr/">LXR</a> 0.3.1 (<a href="http://free-electrons.com/pub/source/lxr-0.3.1-fe1.tar.bz2">source</a>).
&nbsp;&bull;&nbsp;
Linux is a registered trademark of Linus Torvalds
&nbsp;&bull;&nbsp;
<a href="http://free-electrons.com/company/contact/">Contact us</a>
</p>

<div id="menu">
<ul>
   <li><a href="http://free-electrons.com/">Home</a></li>
   <li><a href="http://free-electrons.com/development/" title="Development">Development</a></li>
   <li><a href="http://free-electrons.com/services/" title="Services">Services</a></li>
   <li><a href="http://free-electrons.com/training/" title="Training">Training</a></li>
   <li><a href="http://free-electrons.com/docs/" title="Docs">Docs</a></li>
   <li><a href="http://free-electrons.com/community/" title="Community">Community</a></li>
   <li><a href="http://free-electrons.com/company/" title="Company">Company</a></li>
   <li><a href="http://free-electrons.com/blog/" title="Blog">Blog</a></li>
</ul>
</div>

</div>
</div>
</body>
</html>
