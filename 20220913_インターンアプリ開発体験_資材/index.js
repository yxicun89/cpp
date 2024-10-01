$(function() {
    //ビデオから映像取得
    navigator.mediaDevices.getUserMedia({ video: true })
        .then(function(stream) {
            //ページ上で再生
            //課題(1) 下の???を正しいものに直す
            const player = document.getElementById('???');

            player.srcObject = stream;
        })
        .catch(function(error) {
            console.error(error);
        });

    //課題(2) 撮影ボタンを押したら静止画を撮影して、映像の隣に静止画が表示されるようにする

});

//課題(3) 撮影した静止画を使って解析APIを呼び出す
const faceApi = function(sourceImage) {
    // //FaceApi呼び出し
    // $.ajax({
    //         url: uriBase + "?" + $.param(params),
    //         beforeSend: function(xhrObj) {
    //             xhrObj.setRequestHeader("Content-Type", "application/octet-stream");
    //             xhrObj.setRequestHeader("Ocp-Apim-Subscription-Key", subscriptionKey);
    //         },
    //         type: "POST",
    //         data: makeblob(sourceImage),
    //         processData: false,
    //     })
    //     .done(function(data) {
    //         // API呼び出し結果 画面表示
    //         //➀textAreaという変数を作って、結果を表示したいHTML側の枠の要素（Id）を設定する
    //         //ここに書く！

    //         textArea.innerText = JSON.stringify(data, null, 2);
    //         // 枠線表示
    //         drawFaceline(data);
    //     })
    //     .fail(function(error) {
    //         alert("error");
    //         console.error(error);
    //     });
}

//課題４：顔に枠を出す処理部分を書き、解析結果表示の時に呼び出すようにする
//顔枠線処理//
const drawFaceline = function(data) {

    // data.forEach(function(element, index) {
    //     //顔の位置座標を設定
    //     const faceRe = element.faceRectangle;
    //     //➀faceReに格納されている顔の位置情報を、それぞれleft,top,width,heightという変数を作ってそこに設定する。


    //     //➁変数"canvas"を作り、顔枠を出したい静止画の要素を取得して設定する

    //     const ctx = canvas.getContext('2d');
    //     //枠線の色や太さの設定
    //     ctx.lineWidth = 2;
    //     //➂枠線の色を設定する（RGB方式）
    //     ctx.strokeStyle = "rgb(ここに書く！)";
    //     ctx.strokeRect(left, top, width, height);
    //     // 番号を表示
    //     //➃枠線の上に表示する数字の色を設定する（RGB方式）
    //     ctx.fillStyle = "rgb(ここに書く！)";
    //     ctx.font = "bold 20px 'Arial'";
    //     ctx.fillText(index + 1, left, top);
    // });

}

//引数の画像をBase64に変換
const makeblob = function(dataURL) {
    const BASE64_MARKER = ';base64,';
    if (dataURL.indexOf(BASE64_MARKER) == -1) {
        const parts = dataURL.split(',');
        const contentType = parts[0].split(':')[1];
        const raw = decodeURIComponent(parts[1]);
        return new Blob([raw], { type: contentType });
    }
    const parts = dataURL.split(BASE64_MARKER);
    const contentType = parts[0].split(':')[1];
    const raw = window.atob(parts[1]);
    const rawLength = raw.length;

    const uInt8Array = new Uint8Array(rawLength);

    for (let i = 0; i < rawLength; ++i) {
        uInt8Array[i] = raw.charCodeAt(i);
    }

    return new Blob([uInt8Array], { type: contentType });
}

// APIのKeyなどの設定
const subscriptionKey = "df85f11d94e84b84ae21dc0493536a09";
const uriBase = "https://australiaeast.api.cognitive.microsoft.com/face/v1.0/detect";
const params = {
    "returnFaceId": "true",
    "returnFaceLandmarks": "false",
    "returnFaceAttributes": "age,gender,headPose,smile,facialHair,glasses,emotion,hair,makeup,occlusion,accessories,blur,exposure,noise",
};